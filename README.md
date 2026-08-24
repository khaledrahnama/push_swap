*This activity has been created as part of the 42 curriculum by krahnama, semirkar*

# push_swap

## Description

push_swap sorts a stack of integers using only a small set of stack
operations, split across two stacks called `a` and `b`. You start with
all the numbers unsorted in `a` and an empty `b`, and you're only allowed
to move things around with `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`,
`rra`, `rrb`, `rrr`. That's it. No arrays, no built-in sort, nothing else.

The point of the project isn't really "sort some numbers" — that part is
easy. It's about doing it in as few moves as possible, and understanding
why some approaches scale so much worse than others as the input grows.
To show that, we built four different sorting strategies with different
complexity classes (O(n²), O(n·√n), O(n·log n)), a way to measure how
"disordered" the input is, and an adaptive mode that picks whichever
strategy fits best based on that measurement.

We're not submitting the bonus part (checker) for this one — just the
mandatory push_swap.

## Instructions

### Compiling

```bash
make          # builds push_swap
```

The binary compiles clean with `-Wall -Wextra -Werror`. We don't use
`printf`, `strtok`, `atoi`, or anything like that — only `read`, `write`,
`malloc`, `free`, `exit`. Everything else (number parsing, string helpers,
etc.) is written from scratch in `ft_utils.c`.

```bash
make clean    # remove .o files
make fclean   # remove .o files and the binary
make re       # fclean, then all
```

### Running it

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers>
```

You can pass the numbers as separate arguments or as one quoted string,
either works. If you don't pass a strategy flag it defaults to
`--adaptive`. Flags have to come before the numbers — once the first
number shows up, anything after that is treated as stack data, even if
it looks like a flag.

`--bench` prints some stats to stderr after sorting — the disorder
percentage, which strategy got used, total operations, and a breakdown by
operation type. It doesn't touch stdout, so you can still pipe the actual
sort operations somewhere while watching the bench output separately.

A few examples:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "4 67 3 87 23"
./push_swap --simple 5 4 3 2 1
./push_swap --bench --adaptive $(python3 -c "import random; print(' '.join(map(str, random.sample(range(-500,500),100))))")
```

## The algorithms

All four strategies work on a plain array (not a linked list), with index
0 being the top of the stack. When we talk about complexity below we mean
the number of push_swap operations printed, since that's what actually
gets measured — not how much C-level work our program does behind the
scenes to figure those operations out.

### Simple (O(n²))

This one just repeats "find the smallest thing left in `a`, spin it to
the top, push it to `b`" until `a` is empty. Once everything is in `b`,
it's sitting there largest-on-top, so pushing it all back into `a` in
that order rebuilds it sorted.

It's O(n²) because finding the minimum means scanning what's left in `a`,
and you do that once per element removed.

### Medium (O(n·√n))

We split the range of values into chunks of about `3.5×√n` numbers each.
Starting from the highest chunk and working down, we sweep through `a`
once, sending anything in the current chunk to `b` and rotating everything
else out of the way. Once a chunk is fully in `b` — and only that chunk,
nothing else — we can safely do a small selection sort on `b` (find the
max, rotate it up, push it into `a`) without worrying about disturbing
anything, since `b` doesn't contain any other chunk's numbers at that
point.

That "only that chunk" part matters: rotating never changes the relative
order of things, only pushing does. So as long as each chunk is fully
placed before the next one starts, later sweeps can spin right through
the already-sorted parts without messing them up.

One detail that matters a lot: when we push an element into `b`, if it
falls in the lower half of the current chunk we follow the `pb` with an
`rb`. That costs one extra operation now but leaves `b` roughly ordered
with the larger values near the top, so the drain afterwards finds its
next maximum close to the top instead of halfway down. It cut n=500 from
about 8500 operations to about 7200 on its own, and it does not change
the complexity class — it is still one bounded pass per chunk.

About that `3.5×√n` number — it's not a formula from a textbook, we found
it by testing. Plain `√n` (closer to the "proper" balance between sweep
cost and drain cost) blew past the operation limit for n=500. We swept
multipliers from 1x to 8x; the curve is flat between 3.5x and 4x and gets
worse either side, so we took 3.5x, which was best at n=50 and n=100 and
tied at n=500. It stays a constant multiple of √n, so the chunk count
stays Θ(√n) and the O(n·√n) bound holds — a multiplier that grew with n
would quietly turn this into selection sort.

### Complex (O(n·log n))

This is a radix sort, but instead of sorting by the actual value we sort
by rank — basically "if you lined all the numbers up smallest to biggest,
what position would this one be in." We get the rank by binary-searching
a sorted copy of the values. Then we go bit by bit through the ranks,
starting from the least significant bit: anything with a 0 in that bit
position goes to `b`, anything with a 1 stays in `a` (via rotation), then
we reload `b` back into `a` and move to the next bit. Do that for every
bit needed to represent the largest rank and the stack ends up sorted.

Using rank instead of the raw number means we never have to deal with
negative numbers or how they're stored in binary — ranks are always
plain non-negative integers, so the bit logic stays simple.

Since there are `log₂(n)` bit levels and each one is a full pass over the
stack, that's where the O(n log n) comes from.

### Adaptive

Before doing anything, we measure how "out of order" the stack is —
counting how many pairs are in the wrong order relative to each other,
divided by the total number of pairs. That is the disorder metric from
the subject, and we keep it exactly as the subject defines it: a `double`
between 0 and 1, compared directly against the thresholds. No scaling, no
rescaled integers — `disorder < 0.2` in the code means what it says.

The thresholds live in `push_swap.h` as `LOW_DISORDER` (0.2) and
`HIGH_DISORDER` (0.5), so the selection reads the same as the subject:

```c
if (a->size <= SMALL_STACK_MAX)
    sort_small(a, b, stats);
else if (disorder < LOW_DISORDER)
    sort_simple(a, b, stats);
else if (disorder < HIGH_DISORDER)
    sort_medium(a, b, stats);
else
    sort_complex(a, b, stats);
```

The pair counting itself uses `long` rather than `double`, because the
number of pairs is n(n-1)/2 and that overflows a 32-bit int above about
n=65000; only the final division produces the ratio.

A few things happen depending on what we find:

If the stack is already sorted (disorder is 0, which also covers the
trivial 0/1-element case), we don't do anything at all — no operations,
no output.

For 5 elements or fewer we solve it directly. Three or fewer is handled
with just `sa`/`ra`/`rra`, never touching `b`; all 6 orderings of 3
elements sort in 2 moves or fewer that way. For 4 and 5 we push the
smallest elements to `b` until 3 are left, sort those three, and push
back — 6 moves at worst for n=4, 10 for n=5.

This is not a complexity violation the way the old 4-to-10 Simple
shortcut was. The number of operations here is bounded by a constant
regardless of input, so the routine is O(1), and O(1) sits inside O(n²),
O(n·√n) and O(n·log n) alike — it satisfies whichever regime the disorder
lands in. The old shortcut ran Simple, which really is O(n²) and really
does exceed the tighter two bounds. `--bench` still reports the regime
the disorder actually selected, not the routine that ran.

Everything above 5 elements goes by the disorder thresholds from the
subject — no size-based shortcut. We did originally special-case 4 to 10
elements to always use Simple, because Simple genuinely costs fewer
operations than Medium or Complex up to around n=75-100. But the subject
ties each disorder regime to a required complexity class, and Simple is
O(n²), so using it in the 0.2-0.5 or ≥0.5 regime breaks that requirement
no matter how small n is. That shortcut is gone.

The thresholds, applied at every size above 5:

- under 20% disorder → Simple
- 20% to 50% → Medium
- 50% and above → Complex

Worth knowing: a completely random shuffle tends to land right around 50%
disorder on average, so a lot of "fully random" test cases end up sitting
right on the Medium/Complex boundary. That's just how the metric works,
not something specific to our code.

### Measured results

Operation counts over 30 random shuffles per size (values from
`--bench`, verified by replaying the operation stream):

| n   | simple | medium  | complex  | adaptive |
|-----|--------|---------|----------|----------|
| 50  | 436    | **276** | 467      | 276-467  |
| 100 | 1461   | **728** | 1084     | 856      |
| 500 | 32106  | 7241    | **6784** | 7009     |

Adaptive at small sizes, exhaustively over every permutation — these are
worst cases, not samples:

| n | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|
| avg ops | 0.5 | 1.2 | 4.1 | 7.3 | 22.8 | 26.6 |
| max ops | 1 | 2 | 6 | 10 | 29 | 33 |

The jump between n=5 and n=6 is where the constant-time small-case
routine hands over to the disorder-driven strategies.

Two things worth being upfront about:

- Adaptive is not the best strategy at either size. Because a random
  shuffle lands at ~50% disorder, it sits exactly on the medium/complex
  boundary and flips between the two from run to run, so it averages out
  worse than just picking the right one. At n=100 medium wins; at n=500
  complex wins.
- Neither hits the top performance band (under 700 ops for n=100, under
  5500 for n=500), though both sizes now sit comfortably in the band
  above it. Getting to the top band in the high-disorder regime would
  mean beating radix at O(n·log n) operations, which we did not manage.
- Complex costs *more* than Simple below about n=60. That is not a bug.
  Selection sort spends roughly n²/8 operations while radix spends about
  1.5·n·log₂(n); the two cross over around n=60-75, so at n=50 radix
  genuinely loses (467 against 436). Radix wins by an increasing margin
  from there on — at n=500 it is 6784 against 32106.

### Complexity argument — upper bounds

Time is counted in push_swap operations emitted, not in C-level work, as
the subject requires. Space is auxiliary heap beyond the two stacks
themselves (which are O(n) by definition).

| strategy | time (operations) | auxiliary space |
|---|---|---|
| Simple | O(n²) | O(1) |
| Medium | O(n·√n) | O(n) |
| Complex | O(n·log n) | O(n) |
| Adaptive | O(n²) / O(n·√n) / O(n·log n) by regime | O(n) |

**Simple.** Each of the n extractions rotates the minimum to the top in
at most ⌊n/2⌋ moves (we rotate whichever way is shorter), then one `pb`.
Draining back is n `pa`. Bounded by n·(n/2) + 2n, so O(n²). It allocates
nothing.

**Medium.** The chunk size is 3.5·√n, so the number of chunks is
⌈n / 3.5√n⌉ = O(√n). Each chunk costs one bounded sweep of the stack,
at most n operations, giving O(n·√n) for all sweeps. Each element is
drained with at most ⌊c/2⌋ rotations for chunk size c, and there are c
elements per chunk over O(√n) chunks — O(√n · c²) = O(n·√n) again. Total
O(n·√n). The sorted copy of the values is the O(n) space.

**Complex.** Ranks run 0..n-1, so ⌈log₂ n⌉ bit levels. Each level is one
pass — at most n `pb`/`ra` plus at most n `pa` to reload — so at most 2n
operations per level, O(n·log n) overall. The sorted copy used for the
rank binary search is the O(n) space.

**Adaptive.** For n ≤ 5 it emits a number of operations bounded by a
constant (6 at n=4, 10 at n=5, measured over every permutation), so that
branch is O(1) — which sits inside all three required bounds and
therefore satisfies whichever regime the disorder selects. Above n=5 it
delegates to exactly the strategy its regime requires, so it inherits
that strategy's bound. Computing the disorder itself costs no push_swap
operations at all; it is O(n²) C-level work over the input, done once
before any move is emitted, and allocates nothing.

None of the sorting logic is recursive, so no strategy uses stack depth
beyond O(1). The one recursive function in the project is `ft_putnbr_fd`,
which recurses at most 10 times for a 32-bit int.

We measured the operation counts for every strategy against the subject's
performance requirements (100 and 500 random numbers) — see the table
above for where we actually land — and cross-checked correctness with an
independent Python script that replays the operation stream and checks
that `a` ends sorted and `b` ends empty.

## Resources

- Knuth, _The Art of Computer Programming, Vol. 3_ — background on
  selection sort, radix sort, and complexity in general.
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort) and
  [Bucket sort](https://en.wikipedia.org/wiki/Bucket_sort) on Wikipedia —
  these are basically what our medium and complex strategies are adapted
  from.
- The push_swap subject PDF itself, obviously, for the operation set,
  the disorder formula, and the required complexity classes.

### How we used AI

We used Claude throughout this project, mostly for:

- Walking through how the stack operations behave and tracing algorithms
  by hand before writing any code, instead of just asking for code and
  pasting it in.
- Getting a first draft of each sorting strategy, which we then tested
  and traced ourselves. One of them (the medium strategy's first version)
  turned out to have a real bug — it could infinite-loop on certain
  inputs — which we only caught by testing it, not by assuming it worked.
  We had to redesign that part.
- Debugging Makefile issues.
- Fixing norm violations after running norminette and getting a list of
  errors (too many functions in some files, functions too long, that
  kind of thing).

Everything got tested before we trusted it — exhaustive checks on small
inputs, random stress tests, and an independent Python script that
replays the operations and checks the result — not just taken on faith
because the AI said it should work.

Both of us went through the code together and can explain any part of it.

## Contributions

- **krahnama**:
  stack operations, medium and complex algorithm , debugging

- **semirkar**:
  stack operations, simple and adaptive algorithm, debugging

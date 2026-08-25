*This project has been created as part of the 42 curriculum by krahnama, semirkar*

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
etc.) is written from scratch in `ft_utils.c`. No global variables.

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

`--bench` prints some stats to stderr after sorting: the disorder
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

There's one small trick in the sweep that turned out to matter more than
we expected. When we push something into `b`, if its value falls in the
lower half of the chunk we do an `rb` straight after the `pb`. It costs
one extra operation, but it keeps the bigger values of the chunk near the
top of `b`, so when we drain it back the next maximum is usually already
close to the top instead of buried halfway down. That one line took n=500
from roughly 8500 operations to roughly 7200.

The `3.5×√n` isn't from a textbook, we just tested for it. Plain `√n`
looks like the "correct" balance between sweep cost and drain cost, but
it blew past the operation limit at n=500. We tried multipliers from 1x
up to 8x. Anything between 3.5x and 4x is about the same and both sides
get worse, so we took 3.5x since it was the best of the two at n=50 and
n=100. It's still a constant times √n, which is the part that matters:
the chunk count stays Θ(√n) and the O(n·√n) bound holds. A multiplier
that grew with n would quietly turn this back into selection sort.

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

Before doing anything we measure how out of order the stack is: count how
many pairs are in the wrong order relative to each other, divide by the
total number of pairs. That's the disorder metric from the subject, and
we keep it as the subject defines it — a `double` between 0 and 1 that
gets compared straight against the thresholds. No scaling. `disorder <
0.2` in the code means exactly what it says.

The thresholds are named in `push_swap.h`, so the selection reads more or
less like the subject text:

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

Counting the pairs is done in `long`, not `double`. The number of pairs
is n(n-1)/2, which overflows a 32-bit int somewhere above n=65000, and
only the final division turns it into the ratio.

If the stack is already sorted we print nothing at all. That covers the
0 and 1 element cases too.

Five elements or fewer get solved directly instead of going through the
thresholds. Three or fewer needs only `sa`/`ra`/`rra` and never touches
`b` — all six orderings of three sort in two moves or less. For four and
five we push the smallest values into `b` until three are left, sort
those, and push back. Worst case is 6 moves at n=4 and 10 at n=5, and we
checked that against every permutation, not a sample.

It's fair to ask whether skipping the thresholds like that breaks the
complexity the subject asks for, so here's the argument. The subject says
the internal techniques of the adaptive strategy are entirely up to us,
and that the method chosen for a regime has to run in that regime's
class. Complexity is a statement about growth as n gets large. A cutoff
at a fixed size can't change it, because for any large n the cutoff
branch is never the one that runs — the composite "small routine below 6,
radix above" grows exactly like radix does, so it is O(n·log n), and the
same holds for the other two regimes. This is what introsort and Timsort
do when they drop to insertion sort on short runs, and nobody calls those
O(n²) as a result.

Being honest about the limits of that argument: a cutoff at 5 and a
cutoff at 1000 are identical asymptotically, so the maths alone doesn't
separate a sensible one from a dodge. What makes ours defensible is that
it's small, it costs fewer operations than either alternative at those
sizes (10 at worst against Simple's 15 and radix's 25 for five numbers),
and it's nowhere near the 100 and 500 the project is actually measured
on. Everything at a size where a complexity claim can be tested is
decided by the disorder thresholds and nothing else.

Everything above five elements goes purely by disorder:

- under 20% → Simple
- 20% to 50% → Medium
- 50% and above → Complex

One thing to know when testing: a fully random shuffle averages out at
almost exactly 50% disorder, so a lot of random test cases land right on
the Medium/Complex boundary and can go either way between runs. That's
the metric doing what it's defined to do, not us.

### What `--bench` prints

The strategy line names the routine that actually ran, not the class the
regime would have demanded. It only makes a visible difference at n ≤ 5,
where the small-stack routine runs regardless of disorder:

```
$ ./push_swap --bench 5 4 3 2 1
[bench] disorder: 100.00%
[bench] strategy: Adaptive (Small) / O(1)
[bench] total_ops: 8
```

Disorder is 100% so the high regime applies and asks for O(n·log n). What
ran was O(1), which is inside that. Printing `O(n log n)` there would
have implied the Complex strategy ran, and `--complex 5 4 3 2 1` gives 25
operations rather than 8, so the two outputs would have looked like they
contradicted each other.

Above n=5 the label names the internal strategy, and an adaptive run
labelled `(Complex)` prints exactly the same operations as `--complex`
does on the same input. So the label can be checked instead of trusted.

### Measured results

Operation counts over 30 random shuffles per size, taken from `--bench`
and verified by replaying the operations:

| n   | simple | medium  | complex  | adaptive |
|-----|--------|---------|----------|----------|
| 50  | 436    | **276** | 467      | 276-467  |
| 100 | 1461   | **728** | 1084     | 856      |
| 500 | 32106  | 7241    | **6784** | 7009     |

Adaptive at small sizes, over every permutation rather than a sample:

| n | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|
| avg ops | 0.5 | 1.2 | 4.1 | 7.3 | 22.8 | 26.6 |
| max ops | 1 | 2 | 6 | 10 | 29 | 33 |

The jump between 5 and 6 is where the small-stack routine hands over to
the disorder-driven strategies.

Three things we'd rather say ourselves than have someone find:

Adaptive isn't the best of the four at either size. Random input sits on
the Medium/Complex boundary, so it flips between them and averages out
worse than just picking the right one by hand. Medium wins at n=100,
Complex at n=500.

We land in the second performance band, not the top one (under 700 at
n=100, under 5500 at n=500). Above 50% disorder the subject requires an
O(n·log n) method, and a perfect radix at n=100 already costs
100 × 7 bits = 700 operations before any waste. Beating that band means
finding something cheaper than radix that's still honestly O(n·log n),
and we didn't.

Complex costs more than Simple below roughly n=60. That's real, not a
bug. Selection sort spends about n²/8 operations, radix about
1.5·n·log₂(n), and the curves cross around there — at n=50 radix loses
467 to 436. After the crossover it runs away with it: 1084 against 1492
at n=100, and 6784 against 32106 at n=500.

### Complexity, upper bounds

Time is in push_swap operations printed, not C-level work. Space is heap
we allocate on top of the two stacks, which are O(n) by definition.

| strategy | time (operations) | extra space |
|---|---|---|
| Simple | O(n²) | O(1) |
| Medium | O(n·√n) | O(n) |
| Complex | O(n·log n) | O(n) |
| Adaptive | O(n²) / O(n·√n) / O(n·log n) by regime | O(n) |

Simple does n extractions. Each one rotates the minimum up in at most
⌊n/2⌋ moves, since we always rotate whichever direction is shorter, then
one `pb`. Draining back is another n `pa`. That's n·(n/2) + 2n, so O(n²).
It allocates nothing at all.

Medium uses chunks of 3.5·√n, so there are ⌈n / 3.5√n⌉ = O(√n) of them.
Each chunk is one bounded sweep of at most n operations, giving O(n·√n)
across all the sweeps. Draining costs at most ⌊c/2⌋ rotations per element
for chunk size c, with c elements in each of O(√n) chunks, so O(√n · c²),
which is O(n·√n) again. The sorted copy of the values is the O(n) space.

Complex works on ranks 0..n-1, so there are ⌈log₂ n⌉ bit levels. Each
level is one pass: at most n `pb`/`ra`, then at most n `pa` to reload.
2n per level, O(n·log n) in total. The sorted copy used for the rank
lookup is the O(n) space.

Adaptive inherits both bounds from whichever of the three it delegated
to, so in the worst case that's O(n²) operations and O(n) space, and in
each regime it's the pair on that row of the table. Below n=6 it runs the
small-stack routine instead: at most 6 operations at n=4 and 10 at n=5,
capped by a constant rather than growing with n, so O(1) time, and it
allocates nothing, so O(1) space. What each regime's bound describes is
the composite of those two branches, and since the small one stops being
reachable at n=6 the growth is the delegate's, unchanged. Measuring the disorder before any of
that costs zero push_swap operations. It's O(n²) work down in C, done
once before anything is printed, and it allocates nothing either.

Counting everything the program allocates, there are five places and all
of them are O(n): the two stacks, the joined argument string and the
filtered argv list that parsing builds, and the sorted copy of the values
that Medium and Complex each need. The two parsing buffers are freed
before any sorting starts and the sorted copy is freed before the
strategy returns, so peak usage is O(n) whichever way the program is
invoked.

Nothing in the sorting logic recurses, so stack depth is O(1) throughout.
The only recursive function in the project is `ft_putnbr_fd`, and that
bottoms out after at most 10 calls for a 32-bit int.

We checked the operation counts against the performance requirements for
100 and 500 numbers (the table above shows where we land) and checked
correctness with a Python script that replays the printed operations and
confirms `a` comes out sorted with `b` empty.

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

We used Claude on this project for:

- Talking through how the stack operations behave, and tracing the
  algorithms by hand before writing anything, rather than asking for
  code and pasting it in.
- A first draft of each sorting strategy, which we then tested and
  traced ourselves. The medium strategy's first version had a real bug
  in it — it could infinite-loop on some inputs — and we only found that
  by testing, not by reading it. That part got redesigned.
- Hunting bugs we'd missed. Two of the worse ones were a type mismatch
  in the disorder code that made the program print nothing at all, and
  `sort_tiny` mangling a three-element stack that was already sorted.
  Both were found by testing every permutation rather than by reading.
- Tuning: the `rb` trick in the medium sweep and the chunk multiplier
  both came out of measuring options against each other.
- Makefile problems, and cleaning up norm errors after running
  norminette (too many functions in a file, functions over the line
  limit, that kind of thing).

Everything got tested before we trusted it: exhaustive checks on the
small sizes, random and adversarial stress tests, and the Python replay
script. Nothing went in because the AI said it should work.

Both of us went through the code together and can explain any part of it.

## Contributions

We paired on a lot of this, so most files have both our names on them in
the history. The split below is who owned each piece and drove the design
decisions in it.

**krahnama**

- Medium strategy (`sort_medium.c`, `sort_medium_utils.c`): chunk
  planning, the sweep-and-drain loop, the `rb` trick in the sweep, and
  the testing that settled on a `3.5×√n` chunk size.
- Complex strategy (`sort_complex.c`, `sort_complex_utils.c`): sorting by
  rank instead of value, the binary search that finds a rank, and the
  bit-level passes.
- Command line handling (`main_flags.c`): strategy flags, rejecting a
  repeated or conflicting flag, and splitting flags from stack data.
- The Makefile and `includes/push_swap.h`.

**semirkar**

- Simple strategy (`sort_simple.c`): the min-extraction loop and the
  bidirectional rotate that picks the shorter way round.
- Adaptive strategy (`sort_adaptive.c`): threshold selection, the
  three-element case, and the small-stack routine for four and five.
- Disorder metric (`disorder.c`): pair counting, the sorted check, and
  the two-decimal percentage output.
- Benchmark mode (`bench.c`) and the program flow in `main.c`.

**Both of us**

- The eleven stack operations (`ops_swap.c`, `ops_push.c`,
  `ops_rotate.c`, `ops_rrotate.c`) and the stack itself
  (`stack_utils.c`).
- Argument parsing and error handling (`parsing.c`,
  `parsing_utils.c`, `ft_utils.c`).
- Testing: the Python replay script, the exhaustive small-input checks,
  the random and adversarial stress runs, and norminette cleanup.

We reviewed each other's parts as they landed, and either of us can walk
through any file in the project.

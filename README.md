*This activity has been created as part of the 42 curriculum by krahnama, semirkar.*

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

We split the range of values into chunks of about `2.5×√n` numbers each.
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

About that `2.5×√n` number — it's not some formula from a textbook, we
found it by testing. Plain `√n` (which is closer to the "proper" balance
between sweep cost and drain cost) actually blew past the operation limit
for n=500 in our testing. We tried a bunch of multipliers between 0.5x
and 4x and `2.5x` gave the best results for both n=100 and n=500 without
being a magic number that only works for one specific case.

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
literally counting how many pairs are in the wrong order relative to each
other, divided by the total number of pairs. That's the disorder metric
from the subject. We keep it as a scaled integer instead of a float so we
never have to print a floating point number.

A few things happen depending on what we find:

If the stack is already sorted (disorder is 0, which also covers the
trivial 0/1-element case), we don't do anything at all — no operations,
no output.

For 3 elements or fewer, we solve it directly with just `sa`/`ra`/`rra`,
never touching `b`. We checked all 6 possible orderings of 3 elements by
hand (well, by brute force script) and confirmed every single one can be
sorted in 2 moves or fewer this way, so that's what we hardcoded.

For anything from 4 up to 10 elements, we just use the Simple strategy no
matter what the disorder looks like. We tested this — Simple actually
holds up fine (and is often better) compared to Medium or Complex all the
way up to somewhere around n=75-100. The fancier strategies only start
winning once n is big enough that their extra setup work pays off.

Past that, we go by the disorder thresholds given in the subject:

- under 20% disorder → Simple
- 20% to 50% → Medium
- 50% and above → Complex

Worth knowing: a completely random shuffle tends to land right around 50%
disorder on average, so a lot of "fully random" test cases end up sitting
right on the Medium/Complex boundary. That's just how the metric works,
not something specific to our code.

### On complexity and memory

All four strategies allocate a bit of scratch space (a sorted copy of the
values, freed before returning) — that's O(n) extra memory. None of the
sorting logic is recursive. The one function in the whole project that
does recurse is `ft_putnbr_fd`, which just prints a number digit by digit
— it recurses at most 10 times for a 32-bit int, so it's not really
relevant to anything above.

We checked the operation counts for every strategy against the subject's
performance requirements (100 and 500 random numbers) and cross-checked
correctness with an independent Python script that replays the operation
stream and checks the result.

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

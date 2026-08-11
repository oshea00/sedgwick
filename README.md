# Algorithms in C (Sedgewick, 1990)

Working C implementations of examples from Robert Sedgewick's
**"Algorithms in C"** (1990 edition).

This repository is a growing collection. As new entries are added, each
will be documented here with a short description of the algorithm it
implements and how to build/run it.

## Layout

- `.c` files at the project root, one per example.
- Compiled binaries go into `bin/` (git-ignored).

## Building

Each program is a standalone C file. Compile with any C compiler, e.g.:

```sh
cc -Wall -O2 -o bin/<name> <name>.c
```

## Entries

| File | Source (chapter) | Description |
|------|------------------|-------------|
| `euclid.c` | Ch. 1, Program 1.1 | Euclidean algorithm for computing the greatest common divisor (GCD) of two integers. |
| `lists.c` | Ch. 3 (linked lists) | Circular doubly-terminated linked list: push, pop, iterate, reverse, and free. |

## Usage

Run the compiled program from `bin/`:

```sh
./bin/euclid
./bin/lists
```

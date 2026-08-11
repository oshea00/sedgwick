# Algorithms in C (Sedgewick, 1990)

Working C implementations of examples from Robert Sedgewick's
**"Algorithms in C"** (1990 edition).

This repository is a growing collection. As new entries are added, each
is documented here with a short description of the algorithm it
implements.

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
| `lists.c` | Ch. 3 (lists) | Singly linked list with head/tail sentinels: push at head, pop from head, iterate, reverse, and free. |
| `queues_naive.c` | Ch. 3 (queues, linked-list exercise) | Queue built on a sentinel list with O(1) enqueue and O(n) dequeue (traverses to the end on removal). |
| `queues.c` | Ch. 3 (queues, linked-list exercise) | Queue with explicit head/tail pointers and O(1) enqueue/dequeue. |

## Usage

Run any compiled example from `bin/`:

```sh
./bin/<name>
```

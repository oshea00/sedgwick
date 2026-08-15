/*
 * lists.c
 *
 * A singly linked list implemented with head and tail sentinels.
 *
 * From Robert Sedgewick, "Algorithms in C" (1990), Ch. 3 (lists).
 *
 * `push` inserts at the head in O(1).
 * `pop` removes from the head in O(1).
 */
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Demo: push three items, reverse and display, drain the list, then verify
// push/pop behavior again before freeing all nodes.

#define VALUE_LEN 20

int main(void) {
  list items = create_list();
  char name[VALUE_LEN];
  push(items, "1", VALUE_LEN);
  push(items, "2", VALUE_LEN);
  push(items, "3", VALUE_LEN);
  printf("ITEMS:\n");
  list_items(items);
  reverse_items(items);
  printf("Reversed\n");
  printf("ITEMS:\n");
  list_items(items);
  while (!is_empty(items)) {
    pop(items, name, VALUE_LEN);
    printf("POP: %s\n", name);
  }
  printf("PUSH: Kirk\n");
  push(items, "Kirk", VALUE_LEN);
  printf("ITEMS:\n");
  list_items(items);
  if (pop(items, name, VALUE_LEN))
    printf("POP: %s\n", name);
  if (!pop(items, name, VALUE_LEN))
    printf("Empty List\n");
  free_list(items);
}

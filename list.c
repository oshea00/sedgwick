#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Allocate one list node; abort on out-of-memory.
list allocate_item() {
  list item = (list)malloc(sizeof(struct item));
  if (item == NULL) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  return item;
}

int is_empty(list items) {
  list curr = items->next;
  if (curr == curr->next) {
    return 1;
  } else {
    return 0;
  }
}

// Create an empty list with distinct head and tail sentinels.
list create_list() {
  list head = allocate_item();
  list tail = allocate_item();
  head->next = tail;
  tail->next = tail;
  return head;
}

void push(list items, const char *name, size_t len) {
  list item = allocate_item();
  char *value = (char *)malloc(len);
  if (value == NULL) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  snprintf(value, len, "%s", name);
  item->value = value;
  item->next = items->next;
  items->next = item;
}

int pop(list items, char *out, size_t len) {
  list curr = items->next;
  if (is_empty(items)) {
    *out = '\0';
    return 0;
  } else {
    snprintf(out, len, "%s", curr->value);
    items->next = curr->next;
    free_item(curr);
    return 1;
  }
}

void list_items(list items) {
  list curr = items->next;
  while (curr->next != curr) {
    printf(" %s\n", curr->value);
    curr = curr->next;
  }
}

// Reverse all non-sentinel nodes in-place.
void reverse_items(list items) {
  list prev = items->next;
  list curr = items->next->next;
  while (curr->next != curr) {
    list tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }
  items->next->next = curr;
  items->next = prev;
}

void free_item(list item) {
  free(item->value);
  free(item);
}

void free_list(list items) {
  list curr = items->next;
  while (curr->next != curr) {
    items->next = curr->next;
    free_item(curr);
    curr = items->next;
  }
  free(curr);
  free(items);
}

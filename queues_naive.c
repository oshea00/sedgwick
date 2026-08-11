/*
 * queues_naive.c
 *
 * A queue using a linked list.
 *
 * From Robert Sedgewick, "Algorithms in C" (1990), Ch. 3 (queues). The linked
 * list solution left to the reader.
 *
 * to 'enqueue' a value inserts pushes it into the list.
 * to 'dequeue' a value is to remove the item previous to the tail sentinal.
 *
 * This solution iterates the list until the last item is found,
 * passing the value of the item back to the caller,
 * and freeing the storage used by that item while fixing up the new last item
 * to point to the tail.
 *
 * The operations are enqueue O(1), dequeue O(n) - due to loop to end.
 * We can do better (see queue.c).
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 20

typedef struct item {
  char name[NAME_LEN];
  struct item *next;
} *list;

list create_queue();
void enqueue(const list, const char *);
int dequeue(const list, char *out);
void list_queue(const struct item *const);
void reverse_queue(const list);
void free_queue(list);
int is_empty(const struct item *const);
list allocate_item();

// Allocate one node; abort the program on out-of-memory.
list allocate_item() {
  list item = (list)malloc(sizeof(struct item));
  if (item == NULL) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  return item;
}

// A list is empty when the head points directly at the tail sentinel.
int is_empty(const struct item *const items) {
  list curr = items->next;
  if (curr == curr->next) {
    return 1;
  } else {
    return 0;
  }
}

// Build a circular list of two sentinels: head -> tail -> (tail self).
list create_queue() {
  list head = allocate_item();
  list tail = allocate_item();
  head->next = tail;
  tail->next = tail;
  return head;
}

// Insert a new node right after the head (a stack-like LIFO push).
void enqueue(const list items, const char *name) {
  list item = allocate_item();
  snprintf(item->name, NAME_LEN, "%s", name);
  item->next = items->next;
  items->next = item;
}

// Find, remove and return the node at the end; copy its name to 'out'.
// Returns 1 on success, 0 if the queue was empty.
int dequeue(const list items, char *out) {
  list prev = items;
  list curr = items->next;

  if (is_empty(items)) {
    *out = '\0';
    return 0;
  }

  // iterate until curr is pointing at tail
  while (curr->next->next != curr->next) {
    prev = curr;
    curr = curr->next;
  }

  snprintf(out, NAME_LEN, "%s", curr->name);
  prev->next = curr->next;
  free(curr);

  return 1;
}

// Walk from the head until the tail sentinel, printing each item.
void list_queue(const struct item *const items) {
  list curr = items->next;
  printf("ITEMS:\n");
  while (curr->next != curr) {
    printf(" %s\n", curr->name);
    curr = curr->next;
  }
}

// Reverse the queue in place by flipping each node's "next" pointer.
void reverse_queue(const list items) {
  list prev = items->next;
  list curr = items->next->next;
  printf("Reversing.\n");
  while (curr->next != curr) {
    list tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }
  // Reattach the ends: old head now points at the tail sentinel,
  // and the head sentinel points at the new first item.
  items->next->next = curr;
  items->next = prev;
}

// Free every item node, then the tail and head sentinels.
void free_queue(list items) {
  list curr = items->next;
  while (curr->next != curr) {
    items->next = curr->next;
    printf("FREE: %s\n", curr->name);
    free(curr);
    curr = items->next;
  }
  printf("FREE: tail\n");
  free(curr);
  printf("FREE: head\n");
  free(items);
}

// Demo: enqueue three items, reverse, drain the queue, then enqueue/dequeue one
// more item and confirm the empty case before freeing everything.
int main(void) {
  list items = create_queue();
  char name[NAME_LEN];
  enqueue(items, "1");
  enqueue(items, "2");
  enqueue(items, "3");
  list_queue(items);
  while (!is_empty(items)) {
    dequeue(items, name);
    printf("DEQUEUE: %s\n", name);
  }
  printf("ENQUEUE: Kirk\n");
  enqueue(items, "Kirk");
  if (dequeue(items, name))
    printf("DEQUEUE: %s\n", name);
  if (!dequeue(items, name))
    printf("Queue is empty.\n");
  free_queue(items);
}

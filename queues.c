/*
 * queues.c
 *
 * A more efficient queue using a linked list with head and tail pointers.
 *
 * From Robert Sedgewick, "Algorithms in C" (1990), Ch. 3 (queues). The linked
 * list solution left to the reader.
 *
 * to 'enqueue' a value inserts pushes it into the queue tail.
 * to 'dequeue' a value is to remove the item from the queue head.
 * These operations are both O(1) instead of the more naive O(1) and O(n).
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define VALUE_LEN 20

typedef struct item {
  char name[VALUE_LEN];
  struct item *next;
} item;

typedef struct queue {
  item *head;
  item *tail;
} queue;

queue *create_queue(void);
void enqueue(queue *, const char *);
int dequeue(queue *, char *out);
int queue_empty(const queue *);
void free_queue(queue *);
void list_queue(const queue *);
item *allocate_item(void);

// Allocate a queue
queue *create_queue() {
  queue *q = (queue *)malloc(sizeof *q);
  if (q == NULL) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  q->head = NULL;
  q->tail = NULL;
  return q;
}

// Allocate one node; abort the program on out-of-memory.
item *allocate_item() {
  item *i = (item *)malloc(sizeof *i);
  if (i == NULL) {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
  }
  return i;
}

void list_queue(const queue *q) {
  item *current = q->head;
  printf("QUEUE ITEMS: ");
  while (current != NULL) {
    printf("%s ", current->name);
    current = current->next;
  }
  printf("\n");
}

void enqueue(queue *q, const char *name) {
  item *newitem = allocate_item();
  snprintf(newitem->name, VALUE_LEN, "%s", name);
  newitem->next = NULL;

  if (q->tail == NULL) {
    q->head = newitem;
    q->tail = newitem;
  } else {
    q->tail->next = newitem;
    q->tail = newitem;
  }
}

int dequeue(queue *q, char *out) {
  if (queue_empty(q)) {
    *out = '\0';
    return 0;
  }
  item *i = q->head;
  snprintf(out, VALUE_LEN, "%s", i->name);
  q->head = i->next;
  if (q->head == NULL)
    q->tail = NULL;
  free(i);
  return 1;
}

int queue_empty(const queue *q) { return q->head == NULL; }

// Free every item node, then the queue structure.
void free_queue(queue *q) {
  char name[VALUE_LEN];
  while (!queue_empty(q)) {
    dequeue(q, name);
    printf("FREE: %s\n", name);
  }
  printf("Free Queue.\n");
  free(q);
}

// Demo: enqueue three items, drain the queue, then enqueue/dequeue one
// more item and confirm the empty case before freeing everything.
int main(void) {
  queue *q = create_queue();
  char name[VALUE_LEN];
  enqueue(q, "1");
  enqueue(q, "2");
  enqueue(q, "3");
  list_queue(q);
  while (!queue_empty(q)) {
    dequeue(q, name);
    printf("DEQUEUE: %s\n", name);
  }
  printf("ENQUEUE: Kirk\n");
  enqueue(q, "Kirk");
  if (dequeue(q, name))
    printf("DEQUEUE: %s\n", name);
  if (!dequeue(q, name))
    printf("Queue is empty\n");
  free_queue(q);
}

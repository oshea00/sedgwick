#ifndef LIST
#define LIST
#include <stdlib.h>

typedef struct item {
  char *value;
  struct item *next;
} *list;

list create_list();
void push(list, const char *, size_t len);
int pop(list, char *out, size_t len);
void list_items(list);
void reverse_items(list);
void free_item(list);
void free_list(list);
int is_empty(list);
list allocate_item();

#endif

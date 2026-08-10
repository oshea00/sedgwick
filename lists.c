#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 20

typedef struct item {
    char name[NAME_LEN];
    struct item *next;
} *list;

list create_list();
void push(list, const char *);
int pop(list, char *out);
void list_items(list);
void reverse_list(list);
void free_list(list);
int is_empty(list);
list allocate_item();

list allocate_item() {
    list item = (list) malloc(sizeof(struct item));
    if (item == NULL) {
        fprintf(stderr,"Out of memory.\n");
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

list create_list() {
    list head = allocate_item();
    list tail = allocate_item();
    head->next = tail;
    tail->next = tail;
    return head;
}

void push(list items, const char *name) {
    list item = allocate_item();
    snprintf(item->name,NAME_LEN, "%s", name);
    item->next = items->next;
    items->next = item;
}

int pop(list items, char *out) {
    list curr = items->next;
    if (is_empty(items)) {
        *out = '\0';
        return 0;
    } else {
        snprintf(out,NAME_LEN, "%s", curr->name);
        items->next = curr->next;
        free(curr);
        return 1;
    }
}

void list_items(list items) {
    list curr = items->next;
    printf("ITEMS:\n");
    while (curr->next != curr) {
        printf(" %s\n",curr->name);
        curr = curr->next;
    }
}

void reverse_items(list items) {
    list prev = items->next;
    list curr = items->next->next;    
    printf("Reversing.\n");
    while (curr->next != curr) {
        list tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp; 
    }
    items->next->next = curr;
    items->next = prev;
 }

void free_list(list items) {
    list curr = items->next;
    while (curr->next != curr) {
        items->next = curr->next;
        printf("FREE: %s\n",curr->name);
        free(curr);
        curr = items->next;
    }
    printf("FREE: tail\n");
    free(curr);
    printf("FREE: head\n");
    free(items);
}

int main(void) {
   list items = create_list();
   char name[NAME_LEN];
    push(items,"1");
    push(items,"2");
    push(items,"3");
   list_items(items);
   reverse_items(items);
   list_items(items);
   while (!is_empty(items)) {
       pop(items,name);
       printf("POP: %s\n",name);
   }
   printf("PUSH: Kirk\n");
   push(items,"Kirk");
   list_items(items);
   if (pop(items,name))
       printf("POP: %s\n",name);
   if (!pop(items,name))
       printf("Empty List\n");
   free_list(items);
}

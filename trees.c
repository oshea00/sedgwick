#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char value;
    struct node *left;
    struct node *right;
} node;

node *create_node(char value) {
    node *n = (node *)malloc(sizeof *n);
    n->value = value;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void print_tree(node *n, int level) {
    if (n == NULL)
        return;
    print_tree(n->right, level+1);
    for (int i=0;i<level;i++) { 
        printf("%s","   "); 
    }
    printf("-  %c\n",n->value);
    print_tree(n->left, level+1);
}

void list_inorder(node *n) {
    if (n==NULL)
      return;
    list_inorder(n->left);
    printf("%c ",n->value);
    list_inorder(n->right);
}

void list_preorder(node *n) {
    if (n==NULL)
      return;
    printf("%c ",n->value);
    list_preorder(n->left);
    list_preorder(n->right);
}

void list_postorder(node *n) {
    if (n==NULL)
      return;
    list_postorder(n->left);
    list_postorder(n->right);
    printf("%c ",n->value);
}

void destroy_tree(node *n) {
    if (n == NULL)
        return;
    destroy_tree(n->right);
    destroy_tree(n->left);
    free(n);
}

int main(void) {
    node *tree = create_node('A');
    tree->left = create_node('B');
    tree->right = create_node('C');
    tree->left->left = create_node('D');
    tree->left->right = create_node('E');
    print_tree(tree,0);
    printf("In-order\n");
    list_inorder(tree);
    printf("\nPre-order:\n");
    list_preorder(tree);
    printf("\nPost-order:\n");
    list_postorder(tree);
    printf("\n");
    destroy_tree(tree);
    return 0;
}

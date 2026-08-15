/*
 * trees.c
 *
 * A small binary tree of single-character values, with three recursive
 * traversal orders, a sideways print, and full deallocation.
 *
 * From Robert Sedgewick, "Algorithms in C" (1990), Ch. 5 (trees). The
 * traversal and printing functions are recursive, each visiting every node
 * exactly once, so all are O(n) in the number of nodes.
 *
 * In-order visits left, then node, then right (sorted order for a BST).
 * Pre-order visits node, then left, then right.
 * Post-order visits left, then right, then node.
 *
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    char value;
    struct node *left;
    struct node *right;
} node;

// Allocate a single tree node holding the given value.
node *create_node(char value) {
    node *n = (node *)malloc(sizeof *n);
    n->value = value;
    n->left=NULL;
    n->right=NULL;
    return n;
}

// Print the tree sideways, growing to the right, indented by depth.
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

// In-order traversal: left subtree, node, right subtree.
void list_inorder(node *n) {
    if (n==NULL)
      return;
    list_inorder(n->left);
    printf("%c ",n->value);
    list_inorder(n->right);
}

// Pre-order traversal: node, left subtree, right subtree.
void list_preorder(node *n) {
    if (n==NULL)
      return;
    printf("%c ",n->value);
    list_preorder(n->left);
    list_preorder(n->right);
}

// Post-order traversal: left subtree, right subtree, node.
void list_postorder(node *n) {
    if (n==NULL)
      return;
    list_postorder(n->left);
    list_postorder(n->right);
    printf("%c ",n->value);
}

// Free every node in post-order, children before parents.
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
    printf("In-order:\n");
    list_inorder(tree);
    printf("\nPre-order:\n");
    list_preorder(tree);
    printf("\nPost-order:\n");
    list_postorder(tree);
    printf("\n");
    destroy_tree(tree);
    return 0;
}

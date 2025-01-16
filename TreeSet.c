#include "TreeSet.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Initialize a TreeSet
TreeSet *init_set() {
    TreeSet *set = malloc(sizeof(TreeSet));
    set->root = NULL;
    return set;
}

// Initialize a TreeNode
TreeNode *initialize(int value) {
    TreeNode *t = malloc(sizeof(TreeNode));
    t->left = NULL;
    t->right = NULL;
    t->height = 1; // Initialize height as 1 (not 0)
    t->value = value;
    return t;
}

// Get the height of a node
int get_height(TreeNode *t) {
    return t ? t->height : 0;
}

// Update the height of a node
void update_height(TreeNode *t) {
    if (t) {
        int left_height = get_height(t->left);
        int right_height = get_height(t->right);
        t->height = 1 + (left_height > right_height ? left_height : right_height);
    }
}

// Get the balance factor of a node
int get_balance(TreeNode *t) {
    return t ? get_height(t->left) - get_height(t->right) : 0;
}

// Rotate left
TreeNode *rotate_left(TreeSet *tree, TreeNode *t) {
    TreeNode *right_node = t->right;
    TreeNode *right_left = right_node->left;

    right_node->left = t;
    t->right = right_left;

    update_height(t);
    update_height(right_node);

    return right_node;
}

// Rotate right
TreeNode *rotate_right(TreeSet *tree, TreeNode *t) {
    TreeNode *left_node = t->left;
    TreeNode *left_right = left_node->right;

    left_node->right = t;
    t->left = left_right;

    update_height(t);
    update_height(left_node);

    return left_node;
}

// Add a value to the TreeSet
TreeNode *add_value(TreeSet *tree, TreeNode *t, int value) {
    if (!t) {
        return initialize(value);
    }

    if (value < t->value) {
        t->left = add_value(tree, t->left, value);
    } else {
        t->right = add_value(tree, t->right, value);
    }

    update_height(t);

    int balance = get_balance(t);

    // Perform rotations if necessary
    if (balance > 1 && value < t->left->value) {
        return rotate_right(tree, t);
    }

    if (balance < -1 && value > t->right->value) {
        return rotate_left(tree, t);
    }

    if (balance > 1 && value > t->left->value) {
        t->left = rotate_left(tree, t->left);
        return rotate_right(tree, t);
    }

    if (balance < -1 && value < t->right->value) {
        t->right = rotate_right(tree, t->right);
        return rotate_left(tree, t);
    }

    return t;
}

// Add a value to the tree
void add(TreeSet *tree, int value) {
    tree->root = add_value(tree, tree->root, value);
}

// Print values in the tree (Level Order)
void print_value(TreeSet *tree) {
    TreeNode *t = tree->root;
    if (!t) {
        printf("Tree is empty.\n");
        return;
    }

    Queue *q = initialize_queue();
    push(q, t);
    int idx = 0;

    while (q->size > 0) {
        int q_size = q->size;
        printf("The values in layer %d are: ", idx);

        for (int i = 0; i < q_size; i++) {
            TreeNode *node = pop(q);
            printf("%d ", node->value);
            if (node->left) {
                push(q, node->left);
            }
            if (node->right) {
                push(q, node->right);
            }
        }

        printf("\n");
        idx++;
    }
}

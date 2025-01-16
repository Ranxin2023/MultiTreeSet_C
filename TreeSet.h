#ifndef TREESET_H
#define TREESET_H
#include "stdio.h"
#include "stdlib.h"
typedef struct _TreeNode{
    int height;
    int value;
    struct _TreeNode * left;
    struct _TreeNode * right;
}TreeNode;
typedef struct {
    struct _TreeNode * root;
}TreeSet;
TreeSet * init_set();
TreeNode * initialize(int);
int get_height(TreeNode * );
void update_height(TreeNode * );
int get_balance(TreeNode * );
void add(TreeSet * , int );
TreeNode* add_value(TreeSet* ,TreeNode*,  int );
TreeNode* rotate_left(TreeSet * , TreeNode*);
TreeNode* rotate_right(TreeSet *, TreeNode *);
// void deep_copy(TreeNode* des, TreeNode * src);
void print_value(TreeSet *);
#endif
#ifndef QUEUE_H
#define QUEUE_H
#include"stdio.h"
#include"stdlib.h"
// #include "TreeSet.h"
typedef struct _QueueNode{
    void * value;
    struct _QueueNode* next;
}QueueNode;
typedef struct{
    int size;
    QueueNode * head;
    QueueNode * tail;
}Queue;
QueueNode * build_node(void *);
Queue * initialize_queue();
void push(Queue * q, void * value);
void* pop(Queue * q);
#endif
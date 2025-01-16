#include"queue.h"
QueueNode * build_node(void *value){
    QueueNode * node=malloc(sizeof(QueueNode));
    node->value=value;
    node->next=NULL;
    return node;
}
Queue * initialize_queue(){
    Queue * q=malloc(sizeof(Queue));
    q->head=NULL;
    q->tail=NULL;
    q->size=0;
    return q;
}
void push(Queue * q, void * value){
    if(q->size==0){
        q->head=build_node(value);
        q->tail=q->head;
        q->size=1;
        return ;
    }
    q->tail->next=build_node(value);
    q->tail=q->tail->next;
    q->size+=1;
}
void* pop(Queue * q){
    // if(q->head=NULL){
    //     throw("q is empty");    
    // }
    if (q->size == 0) {
        printf("Error: Attempt to pop from an empty queue.\n");
        return NULL;
    }
    if(q->head==q->tail){
        q->tail=NULL;
    }
    QueueNode * old_node=q->head;
    void * return_value=q->head->value;
    q->head=q->head->next;
    free(old_node);
    q->size-=1;
    return return_value;
}
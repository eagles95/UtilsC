/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx>
 * @file
 *
 * @brief Queue library file
 */

#ifndef QUEUE_H
#define QUEUE_H

#include<object.h>

/**
 * @brief queue node
 *
 */
typedef struct qnode{
	Object* obj;	//object
	struct qnode* next;	//next node in queue
}qnode;

/**
 * @brief queue
 *
 */
typedef struct queue{
	int size;	//current size
	qnode head;	//dummy head node
	qnode* tail;
}queue;


/**
 *
 * queue function signatures
 */
qnode* create_queue_node(Object*);
void destroy_queue_node(qnode*);
queue* create_queue();
void destroy_queue(queue*);
int isEmpty_queue(queue*);
void enqueue_queue(Object*,queue*);
Object* dequeue_queue(queue*);

#endif

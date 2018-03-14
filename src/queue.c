/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx>
 * @file
 *
 * @brief queue source file
 */

#include <object.h>
#include <queue.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/**
 * @brief Creates a queue node.
 *
 * @details Creates a queue node with the @p as object.
 *
 * @param obj Pointer to Object to node.
 *
 * @return Pointer to queue node.
 *
 */
qnode* create_queue_node(Object* obj){
	
	//check
	assert(obj != NULL);

	qnode* node;
	node = malloc(sizeof(qnode*));

	//initialize node
	node->obj = obj;
	node->next = NULL;

	return(node);
}


/**
 * @brief Destroys a queue node.
 *
 * @details Destroys queue node pointed by @p node.
 *
 * @param node Queue node to be destroyed.
 *
 */
void destroy_queue_node(qnode* node){
	free(node);
}


/**
 * @brief Creates a new queue.
 *
 * @details Allocates and initializes a new queue of size 0.
 *
 * @return Pointer to new queue.
 *
 */
queue* create_queue(){
	queue* q;
	q = malloc(sizeof(queue));

	//initialize queue
	q->size = 0;
	q->head.next = NULL;
	q->tail = &q->head;

	return(q);
}


/**
 * @brief Destroys queue.
 *
 * @details Empty the queue poited by @p q and frees it.
 *
 * @param 1 Pointer to destroyed queue.
 *
 */
void destroy_queue(queue* q){
	
	//check
	assert(q != NULL);

	//make queue empty
	while(!isEmpty_queue(q))
		dequeue_queue(q);
	
	free(q);
}


/**
 * @brief Check if queue is empty.
 *
 * @param q Pointer to queue.
 *
 * @return 1-queue is empty,0-queue not empty.
 *
 */
int isEmpty_queue(queue* q){
	
	//check
	assert(q != NULL);

	return (q->size == 0);	
}


/**
 * @brief Enqueue Object into the queue.
 *
 * @details Enqueues the object @p obj into the queue pointed by @p s .
 *
 * @param obj Pointer to Object to be queued.
 *
 * @param s Pointer to queue to be queued.
 *
 */
void enqueue_queue(Object* obj,queue* q){
	
	//check
	assert(obj != NULL);
	assert(q != NULL);

	qnode* node;
	node = create_queue_node(obj);

	//insert on tail of queue
	q->tail->next = node;
	q->tail = node;
	q->size++;
}


/**
 * @brief Dequeue Object from queue.
 *
 * @details Dequeue the top Object from queue pointed by @p s .
 *
 * @param s Pointer to queue.
 *
 * @return Pointer to Object removed from queue.
 *
 */
Object* dequeue_queue(queue* q){
	
	//check
	assert(q != NULL);
	assert(q->size > 0);

	Object* obj;
	qnode* node;

	//unlink node
	node = q->head.next;
	q->head.next = node->next;
	q->size--;
	
	//tail update
	if(q->size == 0)
		q->tail = &q->head;

	//get object
	obj = node->obj;
	destroy_queue_node(node);

	return obj;
}

/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <jfcdias@sga.pucminas.br>
 * @file
 *
 * @brief Priority Queue source file
 */

#include <object.h>
#include <pqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief Creates a new priority queue.
 *
 * @details Allocates and initializes a new queue of size 0 and maximum size of @p maxsize.
 *
 * @param maxsize Maximum size of new priority queue.
 *
 * @return Pointer to new priority queue.
 *
 */
pqueue* create_pqueue(int maxsize){
	//check
	assert(maxsize > 0);

	pqueue* pq;
	Object** objs;

	//allocate memory
	pq = malloc(sizeof(pqueue));
	objs = malloc(sizeof(Object*)*maxsize);

	//initialize each object
	int i;
	for(i=0;i<maxsize;i++)
		objs[i] = NULL;
	
	//set all atributes
	pq->size = 0;
	pq->maxsize = maxsize;
	pq->objects = objs;

	return(pq);
}


/**
 * @brief Destroys priority queue.
 *
 * @details Empty the priority queue poited by @p pq and frees it.
 *
 * @param 1 Pointer to destroyed priority queue.
 *
 */
void destroy_pqueue(pqueue* pq){
	
	//check
	assert(pq != NULL);

	free(pq->objects);
	free(pq);
}


/**
 * @brief Check if priority queue is empty.
 *
 * @param q Pointer to priority queue.
 *
 * @return 1-pqueue is empty,0-pqueue not empty.
 *
 */
int isEmpty_pqueue(pqueue* pq){
	
	//check
	assert(pq != NULL);

	return (pq->size == 0);	
}


/**
 * @brief Check if priority queue is full.
 *
 * @param q Pointer to priority queue.
 *
 * @return 1-pqueue is full,0-pqueue not full.
 *
 */
int isFull_pqueue(pqueue* pq){
	
	//check
	assert(pq != NULL);

	return (pq->size == pq->maxsize);	
}


/**
 * @brief Insert Object into the queue.
 *
 * @details Inserts the object @p obj into the queue pointed by @p pq.
 *
 * @param obj Pointer to Object to be inserted.
 *
 * @param pq Pointer to priority queue to be changed.
 *
 * @return 1-Insertion failed,0-Insertion succeful.
 *
 */
int insert_pqueue(Object* obj,pqueue* pq){
	//check
	assert(obj != NULL);
	assert(pq != NULL);

	//check if full
	if (isFull_pqueue(pq))
		return 1;
	
	//insert object and adjust queue
	int index = ++pq->size;
	int i;
	for(i=index;i > 1 && compare(obj,pq->objects[i/2])<0;i=i/2)
			pq->objects[i] = pq->objects[i/2];

	pq->objects[i] = obj;
	return 0;
}


/**
 * @brief Remove Object from priority queue.
 *
 * @details Remove the top Object from priority queue pointed by @p pq.
 *
 * @param s Pointer to priority queue.
 *
 * @return Pointer to Object removed from queue.
 *
 */
Object* remove_pqueue(pqueue* pq){
	//check
	assert(pq != NULL);
	assert(pq->size > 0);
	
	//get obj and decrease size
	Object* ret = pq->objects[1];
	int index = --pq->size;

	//adjust pqueue
	pq->objects[1] = pq->objects[index];
	int k = 1;	//iterator
	int small = 1;	//smaller child
	Object* obj;	//object to swap
	while(2*k < pq->size){
		//if both childs are bigger or equal -> break
		if((compare(pq->objects[k],pq->objects[2*k])<= 0) && (compare(pq->objects[k],pq->objects[2*k+1]) <= 0))
			break;
		//find smaller child
		else if (compare(pq->objects[2*k],pq->objects[2*k+1]) <= 0)
			small = 2*k;
		else
			small = 2*k + 1;
		
		//swap
		obj = pq->objects[k];
		pq->objects[k] = pq->objects[small];
		pq->objects[small] = obj;
		
		//update k
		k = small;
	}

	return ret;
}

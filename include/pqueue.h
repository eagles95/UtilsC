/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <jfcdias@sga.pucminas.br>
 * @file
 *
 * @brief Priority Queue library file
 */

#ifndef QUEUE_H
#define QUEUE_H

#include<object.h>

/**
 * @brief Priority Queue
 *
 */
typedef struct pqueue{
	int size;	//current size
	int maxsize;	//maximum size 
	Object** objects;	//Objects		
}pqueue;


/**
 * Priority Queue function signatures
 */
pqueue* create_pqueue(int);
void destroy_pqueue(pqueue*);
int isEmpty_pqueue(pqueue*);
int isFull_pqueue(pqueue*);
int insert_pqueue(Object*,pqueue*);
Object* remove_pqueue(pqueue*);

#endif

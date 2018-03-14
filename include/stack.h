/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx>
 * @file
 *
 * @brief Stack library file
 */

#ifndef STACK_H
#define STACK_H

#include <object.h>


/**
 * @brief stack node
 *
 */
typedef struct stackn{
	Object* obj;	//object
	struct stackn* next; //next node in stack
}stackn;



/**
 * @brief stack
 *
 */
typedef struct stack{
	int size;	// current size
	stackn head;	//dummy head node
}stack;


/**
 *
 * stack function signatures
 */

stackn* create_stack_node(Object*);
void destroy_stack_node(stackn*);
stack* create_stack();
void destroy_stack(stack*);
int isEmpty_stack(stack*);
void push_stack(Object*,stack*);
Object* pop_stack(stack*);

#endif

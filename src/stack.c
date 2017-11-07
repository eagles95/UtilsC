/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <jfcdias@sga.pucminas.br>
 * @file
 *
 * @brief stack source file
 */

#include <object.h>
#include <stack.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/**
 * @brief Creates a stack node.
 *
 * @details Creates a stack node with the @p as object.
 *
 * @param obj Pointer to Object to node.
 *
 * @return Pointer to stack node.
 *
 */
stackn* create_stack_node(Object* obj){
	
	//check
	assert(obj != NULL);

	stackn* node;
	node = malloc(sizeof(stackn));

	//initialize node
	node->obj = obj;
	node->next = NULL;

	return(node);
}


/**
 * @brief Destroys a stack node.
 *
 * @details Destroys stack node pointed by @p node.
 *
 * @param node Stack node to be destroyed.
 *
 */
void destroy_stack_node(stackn* node){
	//check
	assert(node != NULL);

	free(node);
}


/**
 * @brief Creates a new stack.
 *
 * @details Allocates and initializes a new stack of size 0.
 *
 * @return Pointer to new stack.
 *
 */
stack* create_stack(){
	stack* s;
	s = malloc(sizeof(stack));

	//initialize stack
	s->size = 0;
	s->head.next = NULL;

	return(s);
}


/**
 * @brief Destroys stack.
 *
 * @details Empty the stack poited by @p s and frees it.
 *
 * @param s Pointer to destroyed stack.
 *
 */
void destroy_stack(stack* s){
	
	//check
	assert(s != NULL);

	//make stack empty
	while(!isEmpty_stack(s))
		pop_stack(s);
	
	free(s);
}


/**
 * @brief Check if stack is empty.
 *
 * @param s Pointer to stack.
 *
 * @return 1-stack is empty,0-stack not empty.
 *
 */
int isEmpty_stack(stack* s){
	
	//check
	assert(s != NULL);

	return (s->size == 0);	
}


/**
 * @brief push Object into the stack.
 *
 * @details Pushes the object @p obj into the stack pointed by @p s .
 *
 * @param obj Pointer to Object to be pushed.
 *
 * @param s Pointer to stack to be pushed.
 *
 */
void push_stack(Object* obj,stack* s){
	
	//check
	assert(obj != NULL);
	assert(s != NULL);

	stackn* node;
	node = create_stack_node(obj);

	//insert on top of stack
	node->next = s->head.next;
	s->head.next = node;
	s->size++;
}


/**
 * @brief Pop Object from stack.
 *
 * @details Pops the top Object from stack pointed by @p s .
 *
 * @param s Pointer to stack.
 *
 * @return Pointer to Object removed from stack.
 *
 */
Object* pop_stack(stack* s){
	
	//check
	assert(s != NULL);
	assert(s->size > 0);

	Object* obj;
	stackn* node;

	//unlink node
	node = s->head.next;
	s->head.next = node->next;
	s->size--;

	//get object
	obj = node->obj;
	destroy_stack_node(node);

	return obj;
}

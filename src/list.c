/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <jfcdias@sga.pucminas.br>
 * @file
 *
 * @brief List source file
 */

#include<object.h>
#include<list.h>
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

/**
 * @brief Creates a list node.
 *
 * @details Creates a list node with the @p as object.
 *
 * @param obj Pointer to Object to node.
 *
 * @return Pointer to list node.
 *
 */
lnode* create_list_node(Object* obj){
	lnode* node;
	node = malloc(sizeof(lnode));
	
	//initialize node
	node->obj = obj;
	node->next = NULL;

	return(node);
}



/**
 * @brief Destroys a list node.
 *
 * @details Destroys list node pointed by @p node.
 *
 * @param node List node to be destroyed.
 *
 */
void destroy_list_node(lnode* node){
	free(node);
}

/**
 * @brief Creates a new list.
 *
 * @details Allocates and initializes a new list of size 0.
 *
 * @return Pointer to new list.
 *
 */
list* create_list(){
	list* l;
	l = malloc(sizeof(list));
	
	//initialize
	l->size = 0;
	l->head.next = NULL;
	l->tail = &l->head;

	return(l);
}


/**
 * @brief Destroys list.
 *
 * @details Empty the list poited by @p s and frees it.
 *
 * @param l Pointer to destroyed list.
 *
 */
void destroy_list(list* l){
	//check
	assert(l!=NULL);

	while(!isEmpty_list(l)){
		remove_begin_list(l);
	}

	free(l);
}

/**
 * @brief Check if list is empty.
 *
 * @param s Pointer to list.
 *
 * @return 1-list is empty,0-list not empty.
 *
 */
int isEmpty_list(list* l){
	return(l->size == 0);
}

/**
 * @brief Insert in begin of list.
 *
 * @param obj Pointer to new Object.
 *
 * @param l Pointer to list.
 *
 */
void insert_begin_list(Object* obj, list* l){
	//check
	assert(obj != NULL);
	assert(l != NULL);

	lnode* node;
	node = create_list_node(obj);

	//insert in start of list
	node->next = l->head.next;
	l->head.next = node;
	l->size++;

	//tail update
	if (l->size == 1)
		l->tail = node;
}

/**
 * @brief Insert in end of list.
 *
 * @param obj Pointer to new Object.
 *
 * @param l Pointer to list.
 *
 */
void insert_end_list(Object* obj, list* l){
	//check
	assert(obj != NULL);
	assert(l != NULL);

	lnode* node;
	node = create_list_node(obj);

	//insert
	l->tail->next = node;
	l->tail = node;
	l->size++;
}

/**
 * @brief Insert some Object after anoter Object.
 *
 * @param new Object to be inserted.
 *
 * @param obj Object to be considered.
 *
 * @param l Pointer to list.
 *
 */
void insert_after_list(Object* new,Object* obj,list* l){
	//check
	assert(new != NULL);
	assert(obj != NULL);
	assert(l != NULL);

	lnode* node;
	lnode* aux;

	//find obj in list
	for(node = &l->head; node != NULL; node = node->next){
		if(node->obj == obj){
			//found it
			aux = create_list_node(new);

			//link new node
			aux->next = node->next;
			node->next = aux;
			l->size++;
		}
	}
}


/**
 * @brief Remove first object from list.
 *
 * @param l Pointer to list.
 *
 * @return Object* pointer to removed Object.
 *
 */
Object* remove_begin_list(list* l){
	//check
	assert(l != NULL);
	assert(l->size > 0);

	Object* obj;
	lnode* node;

	//unlink node
	node = l->head.next;
	l->head.next = node->next;
	l->size--;

	//tail update
	if(l->size == 0)
		l->tail = &l->head;
	
	//get object
	obj = node->obj;
	destroy_list_node(node);

	return (obj);
}


/**
 * @brief Remove last object from list.
 *
 * @param l Pointer to list.
 *
 * @return Object* pointer to removed Object.
 *
 */
Object* remove_end_list(list* l){
	//check
	assert(l != NULL);
	assert(l->size > 0);

	Object* obj;
	lnode* node;

	//iterate until tail
	lnode* iterator = l->head.next;
	int i = 0;
	while (i < l->size){
		node = iterator;
		iterator = iterator->next;
		i++;
	}

	//get object
	obj = node->obj;
	destroy_list_node(node->next);

	return (obj);
}


/**
 * @brief Remove Object after some other Object.
 *
 * @param obj Pointer to iterator Object.
 *
 * @param l Pointer to list.
 *
 * @return Object* pointer to removed Object,NULL if @param obj was not found in list.
 *
 */
Object* remove_after_list(Object* obj,list* l){
	//check 
	assert(l != NULL);
	assert(obj != NULL);
	assert(l->size > 0);

	lnode* node;
	lnode* aux;
	Object* ret = NULL;

	//iterate until obj gets found
	for(node = &l->head; node->next != NULL;node = node->next){
		if(node->obj == obj){
			//extract obj
			aux = node->next;
			ret = aux->obj;

			//unlink node
			node->next = aux->next;
			destroy_list_node(aux);
			l->size--;

			break;
		}
	}

	return(ret);
}

Object* remove_key_list(list* l, int key){
	//check
	assert(l != NULL);
	assert(l->size > 0);

	lnode* node;
	lnode* aux;
	Object* ret = NULL;

	//iterate until key gets found
	for(node = &l->head; node->next != NULL;node = node->next){
		if(node->next->key == key){
			//extract obj
			aux = node->next;
			ret = aux->obj;

			//unlink node
			node->next = aux->next;
			destroy_list_node(aux);
			l->size--;

			break;
		}
	}

	return(ret);
}







/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx> 
 * @file
 *
 * @brief List library file
 */

#ifndef LIST_H
#define LIST_H

#include<object.h>

/**
 * @brief list node
 *
 */
typedef struct lnode{
	Object* obj;	//object
	struct lnode* next;	//next node in list
}lnode;

/**
 * @brief list
 *
 */
typedef struct list{
	int size;	//current size
	lnode head;	//dummy head node
	lnode* tail;
}list;


/**
 *
 * list function signatures
 */
lnode* create_list_node(Object*);
void destroy_list_node(lnode*);
list* create_list();
void destroy_list(list*);
int isEmpty_list(list*);
void insert_begin_list(Object*,list*);
void insert_end_list(Object*,list*);
void insert_after_list(Object*,Object*,list*);
Object* remove_begin_list(list*);
Object* remove_end_list(list*);
Object* remove_after_list(Object*,list*);
Object* remove_by_key_list(list*,int);
Object* get_by_key_list(list*,int);

#endif

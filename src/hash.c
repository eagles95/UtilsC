/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <jfcdias@sga.pucminas.br>
 * @file
 *
 * @brief Hash Source file
 */

#include<list.h>
#include<object.h>
#include<assert.h>
#include<stdlib.h>
#include<hash.h>

static int hash_function(hash* h,int key){
	return(key%h->size);
}

hash* create_hash(int size){
	hash* h;

	//check
	assert(size > 0);

	//allocate hash and set size
	h = malloc(sizeof(hash));
	h->size = size;
	
	//allocate lists of actual table
	h->table = malloc(sizeof(list*)*size);
	int i;
	for(i=0;i<size;i++)
		h->table[i] = create_list();

	return(h);	
}

void destroy_hash(hash* h){
	//check
	assert(h != NULL);
	
	int i;
	for(i=0;i<h->size;i++)
		destroy_list(h->table[i]);

	free(h->table);
	free(h);
}

void insert_hash(Object* obj, hash* h, int key){
	//check
	assert(obj != NULL);
	assert(h != NULL);
	
	//get index for hash
	int index = hash_function(h,key);
	
	//insert on begin of list in index
	insert_begin_list(obj,h->table[index]);
}


Object* remove_hash(hash* h, int key){
	
	//check
	assert(h != NULL);

	//get index for hash
	int index = hash_function(h,key);

	return (remove_key_list(h->table[index],key));
}

Object* get_hash(int,hash*);


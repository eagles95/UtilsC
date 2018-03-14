/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx>
 * @file
 *
 * @brief Hash Source file
 */

#include<list.h>
#include<object.h>
#include<assert.h>
#include<stdlib.h>
#include<hash.h>



/**
 * @brief Hashing function implementation.
 *
 * @param h Pointer to hash.
 *
 * @param key Key to be hashed.
 *
 * @return key mod @param h size.
 *
 */
static int hash_function(hash* h,int key){
	return(key%h->size);
}


/**
 * @brief Create new hash.
 *
 * @param size Size of new hash.
 *
 * @return pointer to new hash.
 *
 */
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


/**
 * @brief Delete hash.
 *
 * @param h Pointer to deleted hash.
 *
 */
void destroy_hash(hash* h){
	//check
	assert(h != NULL);
	
	int i;
	for(i=0;i<h->size;i++)
		destroy_list(h->table[i]);

	free(h->table);
	free(h);
}

/**
 * @brief Insert object in hash.
 *
 * @param obj Pointer to inserted object.
 *
 * @param h Pointer to hash to insert on.
 *
 */
void insert_hash(Object* obj, hash* h){
	//check
	assert(obj != NULL);
	assert(h != NULL);
	
	//get index for hash
	int index = hash_function(h,obj->key);
	
	//insert on begin of list in index
	insert_begin_list(obj,h->table[index]);
}


/**
 * @brief Remove Object from Hash by key value.
 *
 * @param h Pointer to hash.
 *
 * @param key Key to be found.
 *
 * @return Pointer Object removed from hash.
 *
 */
Object* remove_hash(hash* h,int key){
	//check
	assert(h != NULL);

	//get index for hash
	int index = hash_function(h,key);

	return(remove_by_key_list(h->table[index],key));
}


/**
 * @brief Get object by key.
 *
 * @param h Pointer to hash.
 *
 * @param key Key to be found.
 *
 * @return Pointer to Object found.
 *
 */
Object* get_hash(hash* h, int key){
	//check
	assert(h != NULL);
	
	//get index of hash
	int index = hash_function(h,key);

	return(get_by_key_list(h->table[index],key));
}

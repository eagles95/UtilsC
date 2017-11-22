/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <jfcdias@sga.pucminas.br>
 * @file
 *
 * @brief Hash library file
 */

#ifndef HASH_H
#define HASH_H

#include<list.h>
#include<object.h>

/**
 * @brief define hash table
 *
 */
typedef struct hash{
	list** table;	//actual table
	int size;	//size of table (fixed)
}hash;


/**
 *
 * hash function signatures
 */
hash* create_hash(int);
void destroy_hash();
void insert_hash(Object*,hash*);
Object* remove_hash(int,hash*);
Object* get_hash(int,hash*);

#endif

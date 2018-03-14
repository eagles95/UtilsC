/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx>
 * @file
 *
 * @brief Object library file
 */

#include <object.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * @brief compare funcion.
 *
 * @detailed used to insert and sort objects,key is used by default,change it to compare objects differently.
 *
 * @param Object to be compared
 * @param Object to be compared
 *
 * @return positive if a bigger,negative if b bigger,0 if equal.
 *
 */
int compare(Object* a,Object* b){
	//check
	assert(a != NULL);
	assert(b != NULL);
	return (a->key - b->key);
}


/**
 * THIS FILE IS A PART OF THE UtilsC LIBRARY
 * <xxxx@xxxx>
 * @file
 *
 * @brief Object library file
 */

#ifndef OBJECT_H
#define OBJECT_H

/**
 * @brief Object definition.
 *
 * @details Change this to use with the lib with some other object.
 */
typedef struct Object {
	int key;
}Object;

/**
 * signature for compare function
 */
int compare(Object*,Object*);

#endif

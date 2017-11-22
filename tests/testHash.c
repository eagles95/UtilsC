#include <hash.h>
#include <object.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Simple Hash test.
 * 
 * Inserts 200 elements, gets all 200, removes all 200.
 *
 */

int main (){
	hash* h = create_hash(100);
	Object* obj;
	int i;
	
	//insert 200 elements
	for(i=0;i<200;i++){
		obj = malloc(sizeof(Object));
		obj->key = i;
		insert_hash(obj,h);
	}
	
	//gets all 200
	for(i=0;i<200;i++){
		obj = get_hash(h,i);
		printf("Got element from hash with key: %d == %d ?\n",obj->key,i);
	}
	
	//removes all 200	
	for(i=0;i<200;i++){
		obj = remove_hash(h,i);
		printf("Remove element from hash with key: %d == %d ?\n",obj->key,i);
	}
	
	destroy_hash(h);

	return 0;
}

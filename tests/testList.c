#include <list.h>
#include <object.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Simple List test.
 * Inserts 20 in begin,20 in end,gets 20 by key,removes all 40 by key.
 *
 */

int main (){
	list* l = create_list();
	Object* obj;
	int i;

	//insert 20 in begin
	for (i=0;i<20;i++){
		obj = malloc(sizeof(Object));
		obj->key = i;
		insert_begin_list(obj,l);
	}

	//insert 20 in end
	for (i=0;i<20;i++){
		obj = malloc(sizeof(Object));
		obj->key = i+20;
		insert_end_list(obj,l);
	}
	
	//get 20 first by key
	for(i=0;i<20;i++){
		obj = get_by_key_list(l,i);
		printf("Got element with key:  %d == %d ? \n",obj->key,i);
	}
	
	//try to get non-existent key
	obj = get_by_key_list(l,400);
	if(obj == NULL)
		printf("Key does not exist in list\n");
	
	//try to remove non-existent key
	obj = remove_by_key_list(l,400);
	if(obj == NULL)
		printf("Key does not exist in list\n");
	

	//remove all 40
	for(i=0;i<40;i++){
		obj = remove_by_key_list(l,i);
		printf("Removed element with key:  %d == %d ? \n",obj->key,i);
	}
	
	//check if it worked
	if(isEmpty_list(l)){
		printf("test worked!\n");
	}

	destroy_list(l);

	return 0;
}

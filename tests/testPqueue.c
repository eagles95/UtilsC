#include <pqueue.h>
#include <object.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Simple pqueue test.
 * Insertd 20 objects with random keys, removes all 20.
 *
 */

int main (){
	pqueue* pq = create_pqueue(20);
	int i,random;
	Object* obj;
	for(i=0;i<20;i++){
		obj = malloc(sizeof(Object));
		random = rand() % 20;
		printf("inserted with key = %d\n",random);
		obj->key = random;
		insert_pqueue(obj,pq);
	}
	for(i=0;i<20;i++){
		obj = remove_pqueue(pq);
		printf("removed with key = %d\n",obj->key);
	}
	return 0;
}

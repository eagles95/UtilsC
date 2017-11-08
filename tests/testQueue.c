#include <queue.h>
#include <object.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Simple queue test.
 * Queues 50 objects,dequeues 25,queues another 50,dequeues the rest.
 *
 */

int main (){
	queue* q = create_queue();
	int i;
	Object* obj;
	printf("size = %d \n",q->size);
	for(i=0;i<50;i++){
		obj = malloc(sizeof(Object));
		obj->key = i;
		enqueue_queue(obj,q);
	}
	printf("size = %d \n",q->size);

	for(i=0;i<25;i++){
		obj = dequeue_queue(q);
		printf(" dequeued  with key = %d \n",obj->key);
		free(obj);
	}
	printf("size = %d \n",q->size);

	for(i=0;i<50;i++){
		obj = malloc(sizeof(Object));
		obj->key = i+50;
		enqueue_queue(obj,q);
	}
	printf("size = %d \n",q->size);

	while(!isEmpty_queue(q)){
		obj = dequeue_queue(q);
		printf(" dequeued  with key = %d \n",obj->key);
		free(obj);
	}

	printf("size = %d\n",q->size);

	return 0;
}

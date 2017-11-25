#include<pqueue.h>
#include<queue.h>
#include<object.h>
#include<stdio.h>

int main (){
	queue* q = create_queue();
	pqueue* pq = create_pqueue(10);

	destroy_queue(q);
	destroy_pqueue(pq);

	printf("If you're seein this, everything was included successfully\n");
	return 0;
}

#include<queue.h>
#include<stack.h>
#include<pqueue.h>
#include<list.h>
#include<hash.h>
#include<object.h>
#include<stdio.h>

int main (){
	stack* s = create_stack();
	queue* q = create_queue();
	pqueue* pq = create_pqueue(10);
	list* l = create_list();
	hash* h = create_hash(10);

	destroy_stack(s);
	destroy_queue(q);
	destroy_pqueue(pq);
	destroy_list(l);
	destroy_hash(h);

	printf("If you're seein this, everything was included successfully\n");
	return 0;
}

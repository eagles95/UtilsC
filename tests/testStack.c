#include <stack.h>
#include <object.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Simple stack test.
 * Pushes 50 objects then pops all 50.
 *
 */

int main (){
	stack* s = create_stack();
	int i;
	Object* obj;
	printf("size = %d \n",s->size);
	for(i=0;i<50;i++){
		obj = malloc(sizeof(Object));
		obj->key = i;
		push_stack(obj,s);
	}
	printf("size = %d \n",s->size);

	while(!isEmpty_stack(s)){
		obj = pop_stack(s);
		printf("popped with key = %d \n",obj->key);
		free(obj);
	}

	printf("size = %d\n",s->size);

	return 1;
}

#include <stdio.h>
#include "stack.h"
void main()
{
	node stack;
	init_link_stack(&stack);
	is_empty(&stack);
	clear_link_stack(&stack);
	destory_link_stack(&stack);
	get_top(&stack);
	push(&stack,10);
	push(&stack,20);
	push(&stack,30);
	push(&stack,40);
	printf("%d\n",get_length(&stack));
	printf("%d\n",get_top(&stack));
	pop(&stack);
	pop(&stack);
	printf("%d\n",get_length(&stack));
	printf("%d\n",get_top(&stack));
	clear_link_stack(&stack);
}
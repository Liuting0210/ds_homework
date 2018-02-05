#include <stdio.h>
#include "list.h"
void main()
{
	node head;
	init_list(&head);
	int n = 11;
	int k = 3;
	create_list(&head,n);
	printf("%d\n",loop_list(&head,k));
}
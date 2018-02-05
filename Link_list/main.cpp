#include <stdio.h>
#include"link.h"
void main()
{
	node head;
	init_list(&head);
	printf("%d\n",is_empty(&head));
	insert_head(&head, 55);
	insert_head(&head, 44);
	printf("%d\n",is_empty(&head));
	insert_tail(&head, 66);
	insert_tail(&head, 77);
	printf("%d\n",get_length(&head));
	//destory_list(&head);
	//printf("%d\n",is_empty(&head));
	//show_list(&head);
	//delete_head(&head);
	printf("%d\n",delete_head(&head));
	show_list(&head);
	delete_tail(&head);
	show_list(&head);
	printf("%d\n",get_node(&head,2));
	insert_node(&head,1,44);
	show_list(&head);
	printf("%d\n",get_node(&head,1));
	delete_node(&head,2);
	show_list(&head);
	printf("%d\n",getnum_node(&head,55));
	insert_head(&head, 55);
	insert_head(&head, 77);
	show_list(&head);
	//delnum_node(&head,44);
	//show_list(&head);
}
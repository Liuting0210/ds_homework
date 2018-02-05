#include "loop_queue.h"
#include <stdio.h>

void main()
{
	loop_que q;
	init_queue(&q);
	printf("%d\n",is_empty(&q));
	printf("%d\n",is_full(&q));
	en_queue(&q,10);
	en_queue(&q,20);
	en_queue(&q,30);
	en_queue(&q,40);
	en_queue(&q,50);
	en_queue(&q,60);
	en_queue(&q,70);
	en_queue(&q,80);
	en_queue(&q,90);
	printf("%d\n",is_empty(&q));
	printf("%d\n",is_full(&q));
	printf("%d\n",get_head(&q));
	printf("%d\n",get_len(&q));
	de_queue(&q);
	de_queue(&q);
	en_queue(&q,100);
	en_queue(&q,110);
	en_queue(&q,120);
	printf("%d\n",get_len(&q));
	printf("%d\n",get_head(&q));
	printf("%d\n",get_len(&q));
}
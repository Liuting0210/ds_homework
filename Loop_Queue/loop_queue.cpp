
#include "loop_queue.h"
#include <stdlib.h>
#include <assert.h>

void init_queue(loop_que *q)
{
	assert(q);
	for (int i = 0;i <MAXSIZE; i++)
	{
		q->data[i] = 0;
	}
	q->head = 0;
	q->tail = 0;
}

bool is_empty(loop_que *q)
{
	assert(q);
	return (q->head == q->tail);
}

bool is_full(loop_que *q)
{
	assert(q);
	return (q->head == (q->tail+1)%MAXSIZE);
}

elem_type get_head(loop_que *q)
{
	assert(q);
	if (!is_empty(q))
	{
		return q->data[q->head];
	}
	return -1;
	
}

int get_len(loop_que *q)
{
	assert(q);
	return ((q->tail) - (q->head )+ MAXSIZE) % MAXSIZE;
}

bool en_queue(loop_que *q,elem_type value)
{
	assert(q);
	if (!is_full(q))
	{
		q->data[q->tail] = value;
		q->tail = (q->tail + 1)%MAXSIZE;
		return true;
	}
	return false;
}

elem_type de_queue(loop_que *q)
{
	if (!is_empty(q))
	{
		q->head  = (q->head + 1)%MAXSIZE ;
		return q->data[q->head];
	}
	return -1;
}

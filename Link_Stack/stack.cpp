#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

void init_link_stack(node *stack_phead)
{
	assert(stack_phead);
	stack_phead->data = 0;
	stack_phead->next = NULL;
}

bool is_empty(node *stack_phead)
{
	assert(stack_phead);
	return stack_phead->next != NULL;
}

elem_type get_top(node *stack_phead)
{
	assert(stack_phead);
	if (is_empty(stack_phead))
	{
		return stack_phead->next->data;
	}
	return -1;	
}

int get_length(node *stack_phead)
{
	assert(stack_phead);
	int length = 0;
	while(stack_phead->next != NULL)
	{
		length++;
		stack_phead = stack_phead->next;
	}
	return length;
}

void push(node *stack_phead,elem_type value)
{
	assert(stack_phead);
	node *newnode = (node *)malloc(sizeof(node)*1);
	newnode->data = value;
	newnode->next = stack_phead->next;
	stack_phead->next = newnode;
}

node* pop(node *stack_phead)
{
	assert(stack_phead);
	if (is_empty(stack_phead))
	{
		node *temp = stack_phead->next;
		stack_phead->next = stack_phead->next->next;
		return temp;
	}
	return NULL;
}

void clear_link_stack(node *stack_phead)
{
	assert(stack_phead);
	while(stack_phead->next != NULL)
	{
		stack_phead->data = 0;
		stack_phead = stack_phead->next;
	}
	stack_phead->data = 0;
}

void destory_link_stack(node *stack_phead)
{
	assert(stack_phead);
	node *temp;
	while(stack_phead->next != NULL)
	{
		temp = stack_phead->next;
		free(temp);
		stack_phead = stack_phead->next;
	}
	temp = NULL;
}
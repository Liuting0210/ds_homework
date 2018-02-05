#include "list.h"
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
//初始化
void init_list(node *phead)
{
	assert(phead);
	phead->data = 0;
	phead->next = NULL;
}
//判断是否为空
bool is_empty(node *phead)
{
	assert(phead);
	return (phead->next != NULL);
}
//尾插
bool insert_tail(node *phead, elem_type value)
{
	assert(phead);
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	if(is_empty(phead))      //不为空
	{
		node *p = phead->next;
		while (p->next != phead->next)
		{
			p = p->next;
		}
		newnode->next = p->next;
		p->next = newnode;
	}
	else        //为空
	{
		phead->next = newnode;
		newnode->next = newnode;
	}
	
	return true;
}

//创建节点个数为n的列表
node *create_list(node *phead,int n)
{
	assert(phead);
	for (int i = 1;i <= n;i++ )
	{
		insert_tail(phead,i);
	}
	return phead;
}
//删除p的下一个节点
node *delete_node(node *phead,node *p)
{
	assert(phead);
	if (p == NULL)
	{
		return phead;
	}
	else
	{
		node *q = phead->next;
		while(q != p && q->next != phead->next)
		{
			q = q->next;
		}
		if(q->next == phead->next  && q != p)    //删除的节点不存在
		{
			return phead;
		}
		else if(p->next != phead->next)   //要删除的节点不是第一个节点
		{
			node *s = p->next;
			p->next = p->next->next;
			free(s);
			return phead;
		}
		//if(p->next == phead->next)    //要删除的节点是第一个节点
		else
		{
			node *s = p->next;
			p->next = p->next->next;
			phead->next = p->next;
			free(s);
			return phead;
		}
	}
}

int loop_list(node *phead,int k)
{
	node *p = phead;
	while (phead->next->next != phead->next)
	{
		for(int i = 1;i <= k-1;i++)
		{
			p = p->next;
		}
		delete_node(phead,p);
	}
	return phead->next->data;	
}

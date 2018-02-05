#include "list.h"
#include <assert.h>
#include <malloc.h>
#include <stdlib.h>
//��ʼ��
void init_list(node *phead)
{
	assert(phead);
	phead->data = 0;
	phead->next = NULL;
}
//�ж��Ƿ�Ϊ��
bool is_empty(node *phead)
{
	assert(phead);
	return (phead->next != NULL);
}
//β��
bool insert_tail(node *phead, elem_type value)
{
	assert(phead);
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	if(is_empty(phead))      //��Ϊ��
	{
		node *p = phead->next;
		while (p->next != phead->next)
		{
			p = p->next;
		}
		newnode->next = p->next;
		p->next = newnode;
	}
	else        //Ϊ��
	{
		phead->next = newnode;
		newnode->next = newnode;
	}
	
	return true;
}

//�����ڵ����Ϊn���б�
node *create_list(node *phead,int n)
{
	assert(phead);
	for (int i = 1;i <= n;i++ )
	{
		insert_tail(phead,i);
	}
	return phead;
}
//ɾ��p����һ���ڵ�
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
		if(q->next == phead->next  && q != p)    //ɾ���Ľڵ㲻����
		{
			return phead;
		}
		else if(p->next != phead->next)   //Ҫɾ���Ľڵ㲻�ǵ�һ���ڵ�
		{
			node *s = p->next;
			p->next = p->next->next;
			free(s);
			return phead;
		}
		//if(p->next == phead->next)    //Ҫɾ���Ľڵ��ǵ�һ���ڵ�
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

#include<stdio.h>
#include <string.h>
//5
void reverse_print_value(node *phead)
{
	static node *p = phead; 
	node *q = NULL;
	if(p != NULL)
	{
		if(p->next != NULL)
		{
			p = p->next;
			q = p;
			reverse_print_value(p);
			printf("%d\n",q->data); 
		}
	}
}

//13
bool delete_node(node *phead,node *p)
{
	node *q = phead;
	if(phead == NULL || p == NULL)
	{
		return false;
	}
	if(p->next != NULL)//一般情况
	{
		q = p->next;
		p->data = p->next->data;
		p->next = p->next->next;
		free(q);
		return true;
	}
	else if(p->next == NULL)//删除尾结点
	{
		node *s = phead;
		while(s->next != p)
		{
			s=s->next;
		}
		s->next = NULL;
		free(p);
		return true;
	}
}

//15
node *getkthtotail(node *phead,int k)
{
	node *p = phead->next;
	node *q = phead;
	if(k <= 0 || phead == NULL)
	{
		return NULL;
	}
	while( k != 0 )
	{
		if(q->next != NULL)
		{
			q = q->next;
		}
		else
		{
			return NULL;
		}
		k--;

	}
	while( q->next != NULL)
	{
		p = p->next;
		q = q->next;
	}
	return p;
}

//16
node *reverse_list(node *phead)
{
	node *p = phead;
	node *prev = NULL;
	node *reversehead = NULL;
	while(p != NULL)
	{
		node *pnext = p->next;
		if(pnext == NULL)
		{
			reversehead = p;
		}
		p->next = prev;
		prev = p;
		p = pnext;

	}
	return reversehead;	
}
//17

node *merge(node *phead1,node *phead2)
{
	if(phead1->next == NULL)
	{
		return phead2;
	}
	if(phead2->next == NULL)
	{
		return phead1;
	}
	node *p = phead1->next;
	node *q = phead2->next;
	node *phead3 = phead1;
	node *s = phead3;
	while(p != NULL && q != NULL)
	{

		if(p->data > q->data)
		{
			s->next = q;
			q = q->next;
		}
		else
		{
			s->next = p;
			p = p->next;
		}
		s = s->next;
	}
	if(p == NULL)
	{
		s->next = q;
	}
	else
	{
		s->next = p;
	}
	return phead3;
}

//26
void CloneNode(node *phead)
{
	node *pNode = phead;
	while (pNode != NULL)
	{
		node * clonephead = 
	}
	clonephead->data = phead->data;
	clonephead->next = phead->next;
    clonephead->m_pSibling = NULL;


}
//37
node *findFristCommonNode(node *phead1,node *phead2)
{
	assert(phead1 != NULL);
	assert(phead2 != NULL);
	node *p = phead1->next;
	node *q = phead2->next;
	int len1= get_length(phead1);
	int len2= get_length(phead2);
	if(len1 >= len2)
	{
		int len = len1 - len2;
		while(len != 0)
		{
			p = p->next;
			len--;
		}
	}
	else
	{
		int len = len2-len1;
		while(len != 0)
		{
			q = q->next;
			len--;
		}
	}
	while(p->data != q->data)
	{
		if(p == NULL || q == NULL)
		{
			return NULL;
		}
		p = p->next;
		q = q->next;
	}
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = p->data;
	newnode->next = p->next;
	return newnode;
}
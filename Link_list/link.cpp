
#include<stdlib.h>
#include <stdio.h>
#include "link.h"

//1.初始化单链表
void init_list(node *phead)
{
	phead->data = 0;
	phead->next = NULL;
}

//2.判断单链表是否为空，若为空链表，返回true；否则返回false。
bool is_empty(node *phead)
{
	return (phead->next != NULL);
}
//3.获取单链表长度
int get_length(node *phead)
{
	int count = 0;
	while (phead->next != NULL)
	{
		count++;
		phead = phead->next;
	}
	return count;
}
//4.单链表头插法
bool insert_head(node *phead, elem_type value)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = phead->next;
    phead->next = newnode;
	if(phead->next->data == value)
	{
		return true;
	}
	return false;
}
//5.单链表尾插法
bool insert_tail(node *phead, elem_type value)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->data = value;
	while (phead->next != NULL)
	{
		phead = phead->next;
	}
	newnode->next = phead->next;
	phead->next = newnode;
	if (phead->next->data == value)
	{
		return true;
	}
	else
		return false;
}
//6.销毁单链表
void destory_list(node *phead)
{
	if (is_empty(phead))
	{
		free(phead->next);
	}
}
//7.显示链表全部内容
void show_list(node *phead)
{
	phead = phead->next;
	while(phead != NULL)
	{
		printf("%d\n",phead->data);
		phead = phead->next;
	}
}
//8.根据数据域删除结点
bool delnum_node(node *phead,elem_type value)
{
	if (getnum_node(phead,value) == -1)
	{
		return false;
	}
	while(phead->next->next != NULL)
	{
		if(phead->next->next->data != value)
		{
			phead = phead->next;
		}	
	}
	node *p = phead->next;
	phead->next = phead->next->next;
	free(p);
	return true;


}
//9.根据数据域获得结点
int getnum_node(node *phead,elem_type value)
{
	while(phead->next != NULL)
	{
		if(phead->next->data == value)
		{
			return value;
		}
		else
		{
			phead = phead->next;
		}	
	}
	return -1;  //表示没有找到这个数
}
//10.根据位置删除结点
bool delete_node(node *phead,int pos)
{
	if (pos <= 0 || pos > get_length(phead))
	{
		printf("pos is error\n");
		return false;
	}
	else
	{
		for (int i=1;i<pos;i++)
		{
			phead = phead->next;
		}
		node *p = phead->next;
		phead->next = phead->next->next;
		free(p);
		return true;
	}
}
//11.根据位置插入结点
bool insert_node(node *phead,int pos,elem_type value)
{
	if (pos <= 0 || pos > get_length(phead))
	{
		printf("pos is error\n");
		return false;
	}
	else
	{
		node *newnode = (node *)malloc(sizeof(node));
		for (int i=1;i<pos;i++)
		{
			phead = phead->next;
		}
		newnode->data = value;
		newnode->next = phead->next;
		phead->next = newnode;
		return true;
	}
}
//12.根据位置获得结点
int get_node(node *phead,int pos)
{
	if (pos <= 0 || pos > get_length(phead))
	{
		printf("pos is error\n");
		return -1;
	}
	else
	{
		for (int i=1;i<=pos;i++)
		{
			phead = phead->next;
		}
		return phead->data;
	}
}
//13.头删法
bool delete_head(node *phead)
{
	node *p = phead->next;
	phead->next = phead->next->next;
	free(p);
	/*if (p->data == phead->next->data)
	{
		return true;
	}*/
	return true;
}
//14.尾删法
bool delete_tail(node *phead)
{
	while (phead->next->next != NULL)
	{
		phead = phead->next;
	}
	node *p = phead->next;
	phead->next = NULL;
	free(p);
	return true;
}
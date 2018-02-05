#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

void init_sqlist(sqlist *p)//初始化顺序表
{
	p->elem=(elemtype *)malloc(sizeof(elemtype)*init_Size);
	p->len=0;
	p->length=init_Size;
}
void destroy_sqlist(sqlist *p)//销毁定长顺序表
{
	free(p->elem);
	p->elem=NULL;
	p->len=0;
	p->length=0;
}
void clear_sqlist(sqlist *p)//清零顺序表
{
	p->len=0;
}
bool is_empty(sqlist *p)//判断顺序表是否为空
{
	if(p->len==0)
	{
		return true;
	}
	return false;

}
int get_length(sqlist *p)//获得顺序表长度
{
	return p->len;
}
bool insert(sqlist *p,int pos,elemtype val)//根据位置像顺序表中插入元素
{
	if(pos<0||pos>p->len)
	{
		return false;
	}
	if(p->len==p->length)
	{
		inc(p);

	}
	for(int i=p->len-1;i>=pos;i--)
	{
		p->elem[i+1]=p->elem[i];
	}
	p->elem[pos]=val;
	p->len++;
	return true;
}
void inc(sqlist *p)//扩容顺序表，每次增加两个
{
	p->elem=(elemtype *)realloc(p->elem,(p->length+2)*sizeof(elemtype));
	p->length+=2;
}
bool delete_value(sqlist *p,elemtype val)//根据数据项删除表中的元素
{
	for(int i=0;i<p->len;i++)
	{
		if(p->elem[i]==val)
		{
			for(int j=i;j<p->len;j++)
			{
				p->elem[j]=p->elem[j+1];
			}
			p->len--;
			return true;
		}
	}
	return false;

}
bool delete_pos(sqlist *p,elemtype pos)//根据位置删除顺序表中的元素
{
	if(pos>0&&pos<p->len)
	{
		for(int i=pos-1;i<p->len;i++)
	   {
		   p->elem[i]=p->elem[i+1];
	    }
	    p->len--;
	   return true; 
	}
	return false;
}
int search(sqlist *p,elemtype key)//返回查找到的元素的位置
{
	for(int i=0;i<p->len;i++)
	{
		if(p->elem[i]==key)
		{
			return i+1;
		}
	}
	return -1;
}
void show(sqlist *p)//打印顺序表
{
	for(int i=0;i<p->len;i++)
	{
		printf("%d   ",p->elem[i]);
	}
	printf("\n");
}
bool get_elem(sqlist *p,int pos,elemtype *e)//把顺序表中第pos个位置的元素返回给e
{
	if(pos>0&&pos<p->len)
	{
		*e=p->elem[pos-1];
		return true;
	}
	return false;
}
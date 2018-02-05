#include<stdio.h>


#define init_Size 10
typedef int elemtype;

typedef struct{
	elemtype *elem;
	int len;
	int length;

}sqlist;

void init_sqlist(sqlist *p);
void destroy_sqlist(sqlist *p);
void clear_sqlist(sqlist *p);
bool is_empty(sqlist *p);
int get_length(sqlist *p);
bool insert(sqlist *p,int pos,elemtype val);
void inc(sqlist *p);
bool delete_value(sqlist *p,elemtype val);
bool delete_pos(sqlist *p,elemtype pos);
int search(sqlist *p,elemtype key);
void show(sqlist *p);
bool get_elem(sqlist *p,int pos,elemtype *e);
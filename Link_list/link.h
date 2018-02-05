typedef int elem_type; 
typedef struct node 
{
	elem_type data;
	struct node *next;
}node;

//1.初始化单链表
void init_list(node *phead);

//2.判断单链表是否为空，若为空链表，返回true；否则返回false。
bool is_empty(node *phead);

//3.获取单链表长度
int get_length(node *phead);

//4.单链表头插法
bool insert_head(node *phead, elem_type value);

//5.单链表尾插法
bool insert_tail(node *phead, elem_type value);

//6.销毁单链表
void destory_list(node *phead);

//7.显示链表全部内容
void show_list(node *phead);

//8.根据数据域删除结点
bool delnum_node(node *phead,elem_type value);

//9.根据数据域获得结点
int getnum_node(node *phead,elem_type value);

//10.根据位置删除结点
bool delete_node(node *phead,int pos);

//11.根据位置插入结点
bool insert_node(node *phead,int pos,elem_type value);

//12.根据位置获得结点
int get_node(node *phead,int pos);

//13.头删法
bool delete_head(node *phead);

//14.尾删法
bool delete_tail(node *phead);
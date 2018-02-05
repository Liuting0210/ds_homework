typedef int elem_type; 
typedef struct node 
{
	elem_type data;
	struct node *next;
}node;
void init_list(node *phead);
bool insert_tail(node *phead, elem_type value);
bool is_empty(node *phead);
node *create_list(node *phead,int n);
node *delete_node(node *phead,node *p);
int loop_list(node *phead,int k);

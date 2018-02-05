typedef  int elem_type;
typedef struct link_stack_node
{
	elem_type data;
	struct link_stack_node *next;
}node;

void init_link_stack(node *stack_phead);

bool is_empty(node *stack_phead);

elem_type get_top(node *stack_phead);

int get_length(node *stack_phead);

void push(node *stack_phead,elem_type value);

node* pop(node *stack_phead);

void clear_link_stack(node *stack_phead);

void destory_link_stack(node *stack_phead);

double calculate(char *arr);
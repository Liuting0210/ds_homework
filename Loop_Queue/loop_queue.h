
#define MAXSIZE 10
typedef int elem_type;

typedef struct
{
	elem_type data[MAXSIZE];
	int head;
	int tail;
}loop_que;

void init_queue(loop_que *q);

bool is_empty(loop_que *q);

bool is_full(loop_que *q);

elem_type get_head(loop_que *q);

int get_len(loop_que *q);

bool en_queue(loop_que *q,elem_type value);

elem_type de_queue(loop_que *q);

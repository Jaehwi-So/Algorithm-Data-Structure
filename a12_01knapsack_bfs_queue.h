#define MAX_QUEUE_SIZE 100
#define item_num 4
typedef struct TreeNode {
	int weight;
	int profit;
	int i;
	int bound;
} TreeNode;

typedef TreeNode element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int  front, rear;
} Queue;

void init_queue(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);
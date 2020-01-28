#include "a10_tree_leveltrv_queue.h"

//큐 초기화
void init_queue(Queue* q)
{
	q->front = q->rear = 0;
}

//공백 검출
int is_empty(Queue* q)
{
	return (q->front == q->rear);
}

//포화 검출 
int is_full(Queue* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//enqueue
void enqueue(Queue* q, element item)
{
	if (is_full(q)) {
		printf("큐 포화상태");
		exit(1);
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//dequeue
element dequeue(Queue* q)
{
	if (is_empty(q)) {
		printf("큐 공백상태");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}
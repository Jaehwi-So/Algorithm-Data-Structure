#include<stdio.h>
#include<stdlib.h>
#include "a12_tsp_bfs_queue.h"

/*
typedef struct Node {
	int bound;	//현재 마디의 bound값
	int i;	//현재 마디의 수준
	int pt[10];	//현재 마디의 경로
};
*/

//노드 생성
Node create_node() {
	Node n1;
	n1.bound = 0;
	n1.i = 0;
	return n1;
}

//큐 생성
Queue* create_queue() {
	return (Queue*)malloc(sizeof(Queue));
}

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
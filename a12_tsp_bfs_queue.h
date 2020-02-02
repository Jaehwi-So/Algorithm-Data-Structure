#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_QUEUE_SIZE 100

typedef struct Node {
	int bound;	//현재 마디의 bound값
	int i;	//현재 마디의 수준
	int pt[10];	//현재 마디의 경로
}Node;

typedef Node element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int  front, rear;
} Queue;

Node create_node();
Queue* create_queue();
void init_queue(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);
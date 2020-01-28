#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

typedef TreeNode* element;
typedef struct { 
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} Queue;

void error(char* message);
void init_queue(Queue* q);
int is_empty(Queue* q);
int is_full(Queue* q);
void enqueue(Queue* q, element item);
element dequeue(Queue* q);

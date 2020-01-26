#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50
typedef struct queuetype {
	int queue[MAX_SIZE];
	int front, rear;
}Queuetype;

int is_empty(Queuetype* q);
int is_full(Queuetype* q);
void init_queue(Queuetype* q);
void en_queue(Queuetype* q, int num);
int de_queue(Queuetype* q);
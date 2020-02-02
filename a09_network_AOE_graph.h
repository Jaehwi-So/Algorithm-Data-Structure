#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100
typedef int element;


typedef struct GraphNode {
	int vertex;	//정점
	int value;	//현재까지의 작업량
	GraphNode* link;	//링크
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];	//작업량을 나타내는 인접배열
	GraphNode* adj_list[MAX_VERTICES];	//헤드의 배열
	int work_number;	//작업의 수(간선의 수)
	int work_start[MAX_VERTICES * 2];	//작업의 시작 정점
	int work_end[MAX_VERTICES * 2];	//작업의 끝 정점
} GraphType;

//스택
typedef struct Stack {
	element stack[MAX_STACK_SIZE];
	int top;
} Stack;

void init_graph(GraphType* g);
void insert_vertex(GraphType* g, int v);
void insert_edge(GraphType* g, int vertex1, int vertex2, int weight);
void init_stack(Stack* s);
void init_value(GraphType* g, int number);
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);


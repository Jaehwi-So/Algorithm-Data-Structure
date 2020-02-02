#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_STACK_SIZE 100
typedef int element;

typedef struct GraphNode {
	int vertex;
	GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// 정점의 개수
	GraphNode* adj_list[MAX_VERTICES];	//헤드의 배열
} GraphType;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} Stack;

void init_graph(GraphType* g);
void insert_vertex(GraphType* g, int v);
void insert_edge(GraphType* g, int vertex1, int vertex2);
void init_stack(Stack* s);
int is_empty(Stack* s);
int is_full(Stack* s);
void push(Stack* s, element item);
element pop(Stack* s);


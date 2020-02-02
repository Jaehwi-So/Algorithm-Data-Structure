#include <stdio.h>
#include <stdlib.h>
#include"a09_network_AOE_graph.h"
/*
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
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} Stack;
*/

// 그래프 초기화 
void init_graph(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			g->weight[i][j] = 0;
		}
	}
	g->work_number = 0;
}
// 정점 추가
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		printf("정점 개수 초과");
		return;
	}
	g->n++;
}

// 간선 추가, vertex2를 vertex1의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int vertex1, int vertex2, int weight) {
	if (vertex1 >= g->n || vertex2 >= g->n) {
		printf("정점 번호 오류");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = vertex2;
	node->link = g->adj_list[vertex1];
	node->value = 0;
	g->adj_list[vertex1] = node;
	g->weight[vertex1][vertex2] = weight;

	//간선(작업)의 시작정점과 끝정점을 배열(work_start, work_end)에 추가한다.
	for (int i = g->work_number - 1; i >= 0; i--) {
		g->work_start[i + 1] = g->work_start[i];
		g->work_end[i + 1] = g->work_end[i];
	}
	g->work_start[0] = vertex1;
	g->work_end[0] = vertex2;
	g->work_number++;
}

//그래프의 모든 노드의 value값 초기화
void init_value(GraphType* g, int number) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i]; //해당 정점의 헤드부터 NULL까지 순회하며 차수 계산
		while (node != NULL) {
			node->value = number;
			node = node->link;
		}
	}
}

// 스택 초기화 함수
void init_stack(Stack* s) {
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(Stack* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(Stack* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(Stack* s, element item) {
	if (is_full(s)) {
		printf("스택 포화");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(Stack* s) {
	if (is_empty(s)) {
		printf("스택 공백");
		return -1;
	}
	else return s->stack[(s->top)--];
}

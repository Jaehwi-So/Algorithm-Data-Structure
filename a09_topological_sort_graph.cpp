#include <stdio.h>
#include <stdlib.h>
#include"a09_topological_sort_graph.h"


// 그래프 초기화 
void init_graph(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
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
void insert_edge(GraphType* g, int vertex1, int vertex2) {
	if (vertex1 >= g->n || vertex2 >= g->n) {
		printf("정점 번호 오류");
		return;
	}
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = vertex2;
	node->link = g->adj_list[vertex1];
	g->adj_list[vertex1] = node;
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

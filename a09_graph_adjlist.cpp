#include "a09_graph_adjlist.h"

/*
//그래프의 노드
typedef struct GraphNode {
	int vertex;	//정점
	GraphNode* link; //링크
}GraphNode;

//그래프 타입(인접리스트)
typedef struct GraphType {
	int v;	//정점의 개수
	GraphNode* adj_list[MAX_SIZE];     //헤드의 배열
	int visited[MAX_SIZE];	//방문 표시

}GraphType;
*/

//방문 표시 초기화
void setVisited(GraphType* g) {
	for (int i = 0; i < MAX_SIZE; i++) {
		g->visited[i] = 0;
	}
}

//그래프 초기화
void init_graph(GraphType* g) {
	g->v = 0;	//정점 초기화
	for (int i = 0; i < MAX_SIZE; i++) {
		g->adj_list[i] = NULL;	//연결 리스트에서 link 전부 해제 = 간선 초기화
	}
}

//정점 추가
void insert_vertex(GraphType* g, int vertex) {
	if (vertex >= MAX_SIZE) {
		printf("정점 개수 초과");
	}
	else {
		(g->v)++;	//정점 개수 증가
	}
}

//간선 추가
void insert_edge(GraphType* g, int vertex1, int vertex2) {
	if (vertex1 >= g->v || vertex2 >= g->v) {
		printf("정점 번호 오류");
	}
	else {
		GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
		node->vertex = vertex2;
		node->link = g->adj_list[vertex1];
		g->adj_list[vertex1] = node;	//vertex1에 vertex2를 linkedlist에 추가.
	}
}

//연결 리스트 출력
void print_graph(GraphType* g) {

	for (int i = 0; i < g->v; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d", i);
		while (p != NULL) {
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
	}

}











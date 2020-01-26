#include "a09_graph_adjmat.h"

/*
typedef struct GraphType {
	int v;	//정점의 개수 v
	int adj_mat[MAX_SIZE ][MAX_SIZE ];	//인접 행렬
	int visited[MAX_SIZE ];	//방문 표시
}GraphType;
*/

//그래프 초기화
void init_graph(GraphType* g) {
	g->v = 0;	//정점의 개수 초기화
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			g->adj_mat[i][j] = 0;	//인접 행렬 초기화 = 간선이 없는 상태
		}
	}
}

//정점 삽입
void insert_vertex(GraphType* g, int vertex) {
	if (vertex + 1 > MAX_SIZE) {
		printf("정점 개수 초과");
	}
	else {
		(g->v)++;	//정점의 개수 증가
	}
}

//간선 삽입
void insert_edge(GraphType* g, int vertex1, int vertex2) {
	if (vertex1 >= g->v || vertex2 >= g->v) {
		printf("정점 번호 오류");
	}
	else {
		g->adj_mat[vertex1][vertex2] = 1;	//인접 행렬에서 1로 표시
		g->adj_mat[vertex2][vertex1] = 1;
	}
}

//인접행렬 출력
void print_graph(GraphType* g) {
	for (int i = 0; i < g->v; i++) {
		for (int j = 0; j < g->v; j++) {
			printf("%d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}

}

//방문표시 초기화
void setVisited(GraphType* g) {
	for (int i = 0; i < MAX_SIZE; i++) {
		g->visited[i] = 0;
	}
}

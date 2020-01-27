/*
Kruskal의 MST 알고리즘을 구현하여 그래프에서 최소 신장 트리를 구축하기.
탐욕적인 방법으로 간선들을 가중치가 적은 순서대로 집합에 추가한다. 단 이 때 사이클이 도는 간선(root가 같은 간선)은 추가하지 않는다.
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 50
#define INF 1000

int parent[MAX_VERTICES];	//해당 노드의 루트노드를 보여주는 배열

//루트 노드 배열 초기화
void init_set(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = -1;
	}
}

//속하는 집합(루트노드) 반환
int find_set(int curr) {
	if (parent[curr] == -1) {	//루트 노드일경우 
		return curr;	//자기자신 반환
	}
	while (parent[curr] != -1) {	//부모노드가 있다면 루트노드에 도달할 때까지 찾아서
		curr = parent[curr];	
	}
	return curr;	//루트노드 반환
}

//두개의 정점 연결, 속하는 집합을 합친다.
void union_set(int a, int b) {	
	int root1 = find_set(a);	//정점들의 루트노드 찾기
	int root2 = find_set(b);
	if (root1 != root2) {	//루트노드가 다를 경우
		parent[root1] = root2;	//연결
	}
}

//간선
typedef struct Edge {
	int start, end, weight;	//시작점, 끝점
}Edge;

//그래프 G=(V,E)
typedef struct Graph {
	int v;
	Edge edges[2 * MAX_VERTICES];
}Graph;

//그래프 초기화
void init_graph(Graph* g) {
	g->v = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

//간선 삽입
void insert_edge(Graph* g, int start, int end, int weight) {
	g->edges[g->v].start = start;
	g->edges[g->v].end = end;
	g->edges[g->v].weight = weight;
	g->v++;
}

//qsort()에 사용되는 compare함수
int compare(const void* a, const void* b) {
	Edge* x = (Edge*)a;
	Edge* y = (Edge*)b;
	return(x->weight - y->weight);
}

//크루스칼 mst 알고리즘
void kruskal_mst(Graph* g) {
	int u_set, v_set;
	int cur_edges = 0;
	Edge e;

	init_set(g->v);	//부모 노드 집합 초기화
	qsort(g->edges, g->v, sizeof(Edge), compare);	//간선들의 집합을 비용이 낮은 순으로 정렬

	int edge_num = 0;
	while (edge_num < (g->v)) {	//전체 간선들을 비용이 낮은 간선부터 차례로 검사한다.

		e = g->edges[edge_num];	//검사할 간선
		printf("(%d,%d) : %d ", e.start, e.end, e.weight);
		u_set = find_set(e.start);	//시작점의 루트노드
		v_set = find_set(e.end);	//끝점의 루트노드

		if (u_set != v_set) {	//루트가 같지 않다면(사이클을 돌지 않는다)
			printf(" 연결\n");
			union_set(u_set, v_set);	//간선 선택. 연결
			cur_edges++;
		}
		else {
			printf("\n");
		}
		edge_num++;
	}
	printf("연결된 간선의 수 : %d\n", cur_edges);
}

void print_root(Graph* g) {
	printf("vertex :  root \n");
	for (int i = 0; i < g->v; i++) {
		printf("   %d   :   %d \n", i,parent[i]);
	}
}

int main() {

	Graph* g = (Graph*)malloc(sizeof(Graph));
	init_graph(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);


	kruskal_mst(g);
	print_root(g);
	free(g);
	return 0;

}

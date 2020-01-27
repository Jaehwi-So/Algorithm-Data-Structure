/*
Prim의 MST 알고리즘을 구현하여 그래프에서 최소 신장 트리를 구축하기.
시작 정점에서부터 신장 트리 집합을 단계적으로 확장해 나가는 방법. 각 단계마다 최소 비용을 갱신하면서 트리를 구축한다.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 1000

typedef struct Graph {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];	//비용을 나타내는 인접행렬
} Graph;

int selected[MAX_VERTICES];	//방문한 정점
int distance[MAX_VERTICES];	//각 정점으로 갈 때 최소비용

// distance 배열 중 최소 distance를 갖는 정점을 반환
int min_distance_vertex(int n)
{
	int vertex;
	//선택되지 않은 정점이 존재하면 v를 일단 초기화
	for (int i = 0; i < n; i++) {
		if (!selected[i]) {	
			vertex = i;	
			break;
		}
	}

	//선택되지 않은 정점들 끼리 비교하여 최소 distance를 가지는 v 갱신
	for (int i = 0; i < n; i++) {
		if (!selected[i] && (distance[i] < distance[vertex])) {	
			vertex = i;
		}
	}
	return vertex;
}

//distance배열 출력
void print_distance(Graph* g) {
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF) {
			printf("INF ");
		}
		else
		printf("%d ", distance[i]);
	}
	printf("\n");
}

//prim의 mst 알고리즘
void prim_mst(Graph* g, int start)
{

	for (int i = 0; i < g->n; i++) {
		distance[i] = INF;	//각 정점으로 갈 때의 비용 초기화
	}
	distance[start] = 0;	//시작정점. 비용=0

	for (int i = 0; i < g->n; i++) {	//정점들의 개수만큼
		int u;	//u = 추가할 정점
		u = min_distance_vertex(g->n);	//각 정점까지의 distance들 중 최소비용이 드는 정점 u
		selected[u] = 1;	//정점 추가
		if (distance[u] == INF) return;	//종료(u의 distance가 INF = 더이상 갈 수 있는 곳이 없는 경우)

		printf("vertex %d  || ", u);
		print_distance(g);

		for (int v = 0; v < g->n; v++)	//모든 정점들 중에서
			if (g->weight[u][v] != INF) {	
				//방문하지 않은 곳들 중 기존의 거리보다 정점을 추가했을 때 거리가 더 작으면
				if (!selected[v] && g->weight[u][v] < distance[v]) { 
					distance[v] = g->weight[u][v];	//비용 갱신
					//u = 추가된 정점, v = 모든 정점 중 방문하지 않은 곳
				}
			}
	}
}

int main(void)
{
	Graph g = { 7,
	{{ 0, 29, INF, INF, INF, 10, INF },
	{ 29,  0, 16, INF, INF, INF, 15 },
	{ INF, 16, 0, 12, INF, INF, INF },
	{ INF, INF, 12, 0, 22, INF, 18 },
	{ INF, INF, INF, 22, 0, 27, 25 },
	{ 10, INF, INF, INF, 27, 0, INF },
	{ INF, 15, INF, 18, 25, INF, 0 } }
	};
	prim_mst(&g, 0);
	return 0;
}
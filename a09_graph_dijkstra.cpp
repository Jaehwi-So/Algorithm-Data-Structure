/*
Dijkstra의 최단경로 알고리즘을 구현하여 시작 정점에서 다른 모든 정점까지의 최단경로 구하기
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES	100	
#define INF	1000000	

typedef struct Graph {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} Graph;

int distance[MAX_VERTICES]; //시작정점으로부터의 최단경로
int selected[MAX_VERTICES];	//방문한 정점

//최소 비용 정점 선택
int min_distance_vertex(int distance[], int n, int selected[])
{
	int min_dist = 999999;
	int min_vertex = -1;

	//선택되지 않은 정점들 중에서 최소 거리(distance배열에서 최소거리)
	for (int i = 0; i < n; i++)
		if (distance[i] < min_dist && !selected[i]) {	
			min_dist = distance[i];
			min_vertex = i;
		}
	return min_vertex;
}
void print_distance(Graph* g)
{
	printf("distance || ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("selected || ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", selected[i]);
	printf("\n\n");
}

//다익스트라 알고리즘
void path_dijkstra(Graph* g, int start)
{
	for (int i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		selected[i] = 0;
	}
	selected[start] = 1;    /* 시작 정점 방문 표시 */
	distance[start] = 0;
	print_distance(g);
	for (int i = 0; i < g->n - 1; i++) {	//모든 정점의 수만큼
		int u;	// u = 추가할 정점
		u = min_distance_vertex(distance, g->n, selected);	//현재 최소 비용이 드는 정점 선택
		selected[u] = 1;	//정점을 집합에 추가, 간선을 이음

		for (int w = 0; w < g->n; w++) {
			if (!selected[w]) {	//모든 정점들 중 선택되지 않은 정점

				//방문하지 않은 곳들 중 기존의 거리보다 정점을 추가했을 때 거리가 더 작으면 거리갱신
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
				}
				//u = 추가된 정점, w = 모든 정점 중 방문하지 않은 곳
			}
		}
		print_distance(g);
	}
}
int main(void)
{
	Graph g = { 7,
	{{0  ,7  ,INF,INF,3  ,10 ,INF},
	 {7  ,0  ,4  ,10 ,2  ,6  ,INF},
	 {INF,4  ,0  ,2  ,INF,INF,INF},
	 {INF,10 ,2  ,0  ,11 ,9  ,4  },
	 {3  ,2  ,INF,11 ,0  ,INF,5  },
	 {10 ,6  ,INF,9  ,INF,0  ,INF },
	 {INF,INF,INF,4  ,5  ,INF,0   } 
	}
	};
	path_dijkstra(&g, 0);
	return 0;
}
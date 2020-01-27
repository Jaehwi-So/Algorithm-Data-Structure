/*
Floyd의 최단경로 알고리즘을 구현하여 모든 정점에서 다른 모든 정점까지의 최단경로 구하기
정점을 차례로 하나씩 추가하면서 인접행렬을 갱신한다.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES	100	
#define INF	1000000

typedef struct Graph{
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];	//가중치 인접행렬
} Graph;

int temp[MAX_VERTICES][MAX_VERTICES];	//최단경로 결과 행렬

//인접행렬 출력
void print_mat(Graph* g)
{
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			if (temp[i][j] == INF) {
				printf(" * ");
			}
			else {
				printf("%2d ", temp[i][j]);
			}
		}
		printf("\n");
	}
	printf("-------------------------\n");
}

//floyd 최단경로 알고리즘
void floyd(Graph* g)
{
	//가중치 인접행렬 복사
	for (int i = 0; i < g->n; i++)
		for (int j = 0; j < g->n; j++)
			temp[i][j] = g->weight[i][j];
	print_mat(g);

	for (int i = 0; i < g->n; i++) {	//모든 정점들을 차례로 추가하면서
		for (int j = 0; j < g->n; j++) {	//한 정점에서
			for (int k = 0; k < g->n; k++) {	//다른 정점으로
				if (temp[j][i] + temp[i][k] < temp[j][k]) { //추가한 정점에서의 거리가 기존 거리보다 작으면
					temp[j][k] = temp[j][i] + temp[i][k]; //거리 갱신
				}
			}
		}
		print_mat(g);
	}
}

int main(void){
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
	floyd(&g);
	return 0;
}
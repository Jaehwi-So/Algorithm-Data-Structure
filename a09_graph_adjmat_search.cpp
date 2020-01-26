#include "a09_graph_adjmat_search.h"

//너비 우선 탐색 BFS
void bfs_mat(GraphType* g, int v) {

	Queuetype* q;
	q = (Queuetype*)malloc(sizeof(Queuetype));
	init_queue(q);
	g->visited[v] = 1;

	printf("%d ", v);
	en_queue(q, v);

	while (!is_empty(q)) {
		v = de_queue(q);	//큐에서 백트래킹 지점 dequeue
		for (int i = 0; i < g->v; i++) {	//정점 검사
			if (g->adj_mat[v][i] && !g->visited[i]) {     //방문하지 않았고, 인접해 있으면
				g->visited[i] = 1;	//방문
				printf("-> %d ", i);
				en_queue(q, i);	//해당 정점 백트래킹 지점으로 enqueue
			}
		}
	}
}

//깊이 우선 탐색 DFS
void dfs_mat(GraphType* g, int v) {
	g->visited[v] = 1;
	printf("%d", v);
	for (int i = 0; i < g->v; i++) {	//정점 검사
		if (g->adj_mat[v][i] && !g->visited[i]) {     //방문하지 않았고, 인접해 있으면
			printf(" -> ");
			dfs_mat(g, i);	//해당 정점 기준으로 탐색 시작(깊이우선)
		}
	}
}


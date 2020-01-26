#include "a09_graph_adjlist_search.h"

void dfs_list(GraphType* g, int v) {
	g->visited[v] = 1;
	printf("%d", v);
	GraphNode* i;
	for (i = g->adj_list[v]; i; i = i->link) {	//인접 정점들 중에서
		if (!g->visited[i->vertex]) {	//방문하지 않았다면
			printf(" -> ");
			dfs_list(g, i->vertex);	//방문 후 그 지점부터 탐색
		}
	}
}

void bfs_list(GraphType* g, int v) {
	g->visited[v] = 1;
	GraphNode* i;
	Queuetype* q;
	q = (Queuetype*)malloc(sizeof(Queuetype));
	init_queue(q);
	en_queue(q, v);	//시작정점을 큐에 enqueue
	printf("%d", v);
	while (!is_empty(q)) {
		v = de_queue(q);	//백트래킹 지점 dequeue
		for (i = g->adj_list[v]; i; i = i->link) {	//인접한 정점들 중
			if (!g->visited[i->vertex]) {	//방문하지 않았으면
				g->visited[i->vertex] = 1;
				printf(" -> %d", i->vertex);	//방문
				en_queue(q, i->vertex);	//정점 큐에 백트래킹 지점으로 저장
			}
		}

	}
	free(q);
}

#include<stdio.h>
#include<stdlib.h>
#include "a09_graph_adjlist_search.h"

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	init_graph(g);

	for (int i = 0; i < 9; i++) {
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 0);
	insert_edge(g, 0, 8);
	insert_edge(g, 8, 0);
	insert_edge(g, 2, 3);
	insert_edge(g, 3, 2);
	insert_edge(g, 2, 4);
	insert_edge(g, 4, 2);
	insert_edge(g, 2, 5);
	insert_edge(g, 5, 2);
	insert_edge(g, 2, 8);
	insert_edge(g, 8, 2);
	insert_edge(g, 4, 7);
	insert_edge(g, 7, 4);
	insert_edge(g, 5, 6);
	insert_edge(g, 6, 5);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 6);
	insert_edge(g, 6, 8);
	insert_edge(g, 8, 6);

	printf("인접 리스트 출력\n");
	print_graph(g);

	setVisited(g);
	printf("\nDFS Start : ");
	dfs_mat(g, 0);

	setVisited(g);
	printf("\nBFS Start : ");
	bfs_mat(g, 0);

	return 0;
}
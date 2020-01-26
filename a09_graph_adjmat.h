#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50
typedef struct GraphType {
	int v;
	int adj_mat[MAX_SIZE][MAX_SIZE];
	int visited[MAX_SIZE];
}GraphType;

void init_graph(GraphType* g);
void insert_vertex(GraphType* g, int vertex);
void insert_edge(GraphType* g, int vertex1, int vertex2);
void print_graph(GraphType* g);
void setVisited(GraphType *g);

#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 50
typedef struct GraphNode {
	int vertex;
	GraphNode* link;
}GraphNode;

typedef struct GraphType {
	int v;
	GraphNode* adj_list[MAX_SIZE];     //헤드의 배열
	int visited[MAX_SIZE];

}GraphType;

void setVisited(GraphType* g);
void init_graph(GraphType* g);
void insert_vertex(GraphType* g, int vertex);
void insert_edge(GraphType* g, int vertex1, int vertex2);
void print_graph(GraphType* g);

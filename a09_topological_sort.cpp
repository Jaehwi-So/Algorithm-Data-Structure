//위상 정렬
#include <stdio.h>
#include <stdlib.h>
#include "a09_topological_sort_graph.h"

//모든 정점의 진입차수를 계산
int* get_degree(GraphType* g, int* degree) {
	for (int i = 0; i < g->n; i++) {	
		degree[i] = 0;
	}
	//모든 정점의 인접 리스트를 조사하며 진입 차수 계산
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i]; //해당 정점의 헤드부터 NULL까지 순회하며 차수 계산
		while (node != NULL) {
			degree[node->vertex]++;
			node = node->link;
		}
	}
	return degree;
}

//위상 정렬
void topological_sort(GraphType* g) {
	Stack* s = (Stack*)malloc(sizeof(Stack));
	GraphNode* node;
	init_stack(s);

	int* degree = (int*)malloc((g->n) * sizeof(int));
	degree = get_degree(g, degree);	//정점마다의 진입 차수 계산

	// 진입 차수가 0인 정점을 스택에 삽입
	for (int i = 0; i < g->n; i++) {
		if (degree[i] == 0) {
			push(s, i);
		}
	}
	//위상 순서 결정
	int del_n; //제거할 노드
	while (!is_empty(s)) {
		del_n = pop(s); //정점 제거
		printf("[%d]->", del_n);		//정점 출력
		node = g->adj_list[del_n];	//node == pop된 것의 헤드노드

		while (node != NULL) {	//pop된 노드의 연결 리스트 전체 노드의 진입차수 감소시킨다.(연결 해제)
			int idx = node->vertex;	//헤드 노드의 index
			degree[idx]--;			//진입 차수를 감소
			if (degree[idx] == 0) {	//이때 차수가 0인 것이 생기면 push
				push(s, idx);		
			}	
			node = node->link;   // 다음 링크로 이동
		}
	}
	free(s);
	free(degree);
}
//	
int main(void)
{
	GraphType* g = (GraphType*)malloc(sizeof(GraphType));

	init_graph(g);
	insert_vertex(g, 0);
	insert_vertex(g, 1);
	insert_vertex(g, 2);
	insert_vertex(g, 3);
	insert_vertex(g, 4);
	insert_vertex(g, 5);

	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 3);
	insert_edge(g, 1, 4);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 5);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 5);
	topological_sort(g);
	free(g);
	return 0;
}
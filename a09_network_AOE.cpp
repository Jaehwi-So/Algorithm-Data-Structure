/*AOE 네트워크 구축하기
정점 : 사건(event) - 작업의 시작 또는 종료
간선 : 작업(필요 시간 명시)
#earlist : 각각의 정점이 실행되는 가장 빠른 시간
#latest : 각각의 정점이 실행되는 가장 늦은 시간
#early : 각각의 간선이 실행되는 가장 빠른 시간
#late : 각각의 간선이 실행되는 가장 늦은 시간
#early - late = 0 이면 임계작업. 해당 작업의 속도가 전체 프로젝트의 속도를 좌우한다.
*/
#include <stdio.h>
#include <stdlib.h>
#include "a09_network_AOE_graph.h"

int earliest[MAX_VERTICES];	//정점 i가 일어날 수 있는 가장 빠른 시간
int latest[MAX_VERTICES];	//정점 i가 일어날 수 있는 가장 늦은 시간
int early[MAX_VERTICES * 2];	//간선 e가 실행될 수 있는 가장 빠른 시간
int late[MAX_VERTICES * 2];	//간선 e가 실행될 수 있는 가장 늦은 시간


// # 모든 정점의 진입차수를 계산 
int* get_in_degree(GraphType* g, int* degree) {
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

// # Earliest[] 구하기
void get_earliest(GraphType* g) {
	printf("earlist 계산\n");
	for (int i = 0; i < g->n; i++) {
		earliest[i] = 0;
	}
	Stack* s = (Stack*)malloc(sizeof(Stack));
	GraphNode* node;
	init_stack(s);

	int* degree = (int*)malloc((g->n) * sizeof(int));
	degree = get_in_degree(g, degree);	//정점마다의 진입 차수 계산

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
		printf("%d 출력 : ", del_n);		//정점 출력
		node = g->adj_list[del_n];	//node == pop된 것의 헤드노드

		while (node != NULL) {	//pop된 노드의 연결 리스트 전체 노드의 진입차수 감소시킨다.(연결 해제)
			int idx = node->vertex;	//헤드 노드의 index
			degree[idx]--;			//진입 차수를 감소
			if (earliest[idx] < earliest[del_n] + g->weight[del_n][idx]) {//이 때 더 큰 earliest값을 갱신
				earliest[idx] = earliest[del_n] + g->weight[del_n][idx];
				node->value = earliest[idx];
			}
			if (degree[idx] == 0) {	//차수가 0인 것이 생기면 push
				push(s, idx);
			}
			node = node->link;   // 다음 링크로 이동
		}
		printf("earlist : [ ");
		for (int i = 0; i < g->n; i++) {
			printf("%d ", earliest[i]);
		}
		printf("]\n");
	}
	free(s);
	free(degree);
}

// # 진출차수 구하기
int* get_out_degree(GraphType* g, int* degree) {
	for (int i = 0; i < g->n; i++) {
		degree[i] = 0;
	}
	//모든 정점의 인접 리스트를 조사하며 진출 차수 계산
	for (int i = 0; i < g->n; i++) {
		GraphNode* node = g->adj_list[i]; //해당 정점의 헤드부터 NULL까지 순회하며 차수 계산
		while (node != NULL) {
			degree[i]++;	
			node = node->link;
		}
	}
	return degree;
}

// # Latest[] 구하기
void get_latest(GraphType* g) {
	printf("latest 계산\n");
	bool del_node[MAX_VERTICES];	//출력된 노드를 나타낼 배열
	for (int i = 0; i < g->n; i++) {
		del_node[i] = 0;
	}

	for (int i = 0; i < g->n; i++) {	//latest[] 초기화
		latest[i] = earliest[g->n-1];
	}
	Stack* s = (Stack*)malloc(sizeof(Stack));
	init_stack(s);
	init_value(g, latest[g->n]);

	int* degree = (int*)malloc((g->n) * sizeof(int));
	degree = get_out_degree(g, degree);	//정점마다의 진출 차수 계산

	// 진출 차수가 0인 정점을 스택에 삽입
	for (int i = 0; i < g->n; i++) {
		if (degree[i] == 0) {
			push(s, i);
			del_node[i] = 1;
		}
	}
	//위상 순서 결정
	int del_n; //제거할 노드
	while (!is_empty(s)) {
		del_n = pop(s); //정점 제거
		printf("%d 출력 : ", del_n);		//정점 출력

		for (int i = 0; i < g->n; i++) {
			if (g->adj_list[i] != NULL) {
				GraphNode* node = g->adj_list[i]; //모든 정점의 헤드부터 NULL까지 순회하며 차수 계산
				while (node != NULL) {
					int idx = node->vertex;	//헤드 노드의 index
					if (idx == del_n) {	//pop된 노드가 인접 리스트에 존재할 시 해당 정점의 진출차수 줄임
						degree[i]--;
						if (latest[i] > latest[del_n] - g->weight[i][del_n]) {	//이때 더 작은 latest[]값 갱신
							latest[i] = latest[del_n] - g->weight[i][del_n];
							node->value = latest[i];
						}
					}
					node = node->link;
				}
				if (degree[i] == 0 && del_node[i] != 1) {	//이때 삭제되지 않은 노드 중 차수가 0인 것이 생기면 push
					push(s, i);
					del_node[i] = 1;
				}
			}
		}
		printf("latest : [ ");
		for (int i = 0; i < g->n; i++) {
			printf("%d ", latest[i]);
		}
		printf("]\n");
	}
	free(s);
	free(degree);
}

// # 임계작업 구하기
void get_critical_path(GraphType *g) {
	int start;
	int end;
	for (int i = 0; i < g->work_number; i++) {
		start = g->work_start[i];
		end = g->work_end[i];
		early[i] = earliest[start];	//early(i)=earlist(간선의 시작정점)
		late[i] = latest[end] - g->weight[start][end];	//late(i)=latest(간선의 끝정점)-작업 i의 수행시간
		printf("작업 <%d->%d> : %d [early %d] [late %d] ",start, end, g->weight[start][end], early[i], late[i]);
		if (late[i] - early[i] == 0) {	//late와 early가 같으면 임계작업
			printf("critical path\n");
		}
		else{
			printf("\n");
		}
	}
}
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
	insert_vertex(g, 6);

	insert_edge(g, 5, 6, 4);
	insert_edge(g, 4, 6, 4);
	insert_edge(g, 3, 5, 5);
	insert_edge(g, 3, 4, 3);
	insert_edge(g, 2, 3, 2);
	insert_edge(g, 1, 3, 3);
	insert_edge(g, 0, 2, 3);
	insert_edge(g, 0, 1, 4);

	get_earliest(g);
	get_latest(g);
	get_critical_path(g);
	free(g);
	return 0;
}
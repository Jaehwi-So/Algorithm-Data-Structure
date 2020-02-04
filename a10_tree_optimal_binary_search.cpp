/*
#최적 이진 탐색 트리 구축(Optimal Binary Search Tree, OBST)
서로 다른 식별자들이 있다. 이 식별자들은 탐색 확률과 존재 확률(실패 확률)이 존재한다.
검색의 비용(비교횟수)를 최소화하는 최적 이진 탐색 트리를 구축한다.
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_GRAPH_SIZE 5

//전위 순회
void preorder_tree(int i, int j, int r[][MAX_GRAPH_SIZE], int root, int type) {
	if (i == j) {
		if (type == 0) {
			printf("[root node : %d]\n", i);
		}
		if (type == 1) {
			printf("[%d -> left node : %d]\n", root, i);
		}
		if (type == 2) {
			printf("[%d -> right node : %d]\n", root, i);
		}
		return;
	}
	if (i > j) {
		return;
	}
	else {
		int k = r[i][j];	//T[ij]의 k값(루트노드)
		if (type == 0) {
			printf("[root node : %d]\n", k);
		}
		if (type == 1) {
			printf("[%d -> left node : %d]\n", root, k);
		}
		if (type == 2) {
			printf("[%d -> right node : %d]\n", root, k);
		}
		preorder_tree(i, k - 1, r, k, 1);	//루트노드를 기점으로 왼쪽 서브트리 계산
		preorder_tree(k + 1, j, r, k, 2);	//루트노드를 기점으로 오른쪽 서브트리 계산
	}
}

//최소 비용이 드는 루트 노드 반환
int knuth_min(int cost[][MAX_GRAPH_SIZE], int root[][MAX_GRAPH_SIZE], int i, int j) {
	int min = INT_MAX;
	int minLocate = 0;
	for (int k = i + 1; k <= j; k++) {
		if (cost[i][k - 1] + cost[k][j] < min) {	//왼쪽 서브트리의 cost + 오른쪽 서브트리의 cost가 최소가 되는 k값
			min = cost[i][k - 1] + cost[k][j];
			minLocate = k;
		}
	}
	root[i][j] = minLocate;
	return root[i][j];
}

void op_bin_search(int p[], int q[], int cost[][MAX_GRAPH_SIZE], int root[][MAX_GRAPH_SIZE], int weight[][MAX_GRAPH_SIZE], int n) {
	/*
	a(1~n) : 서로 다른 식별자 	(1<=i<=j<=n)
	p(1~n) : 식별자를 탐색할 확률, q(0~n) : 식별자가 존재할 확률
	root : T(i,j)의 루트
	cost : T(i,j)의 비용	= 방문시 비교횟수
	weight : T(i,j)의 가중치

	식별자 a(j)에 대한 최적 이진트리 구축에 드는 비용과 트리의 루트와 가중치 구하기
	*/

	//0 또는 1개의 노드를 가진 트리 초기화
	for (int i = 0; i < n; i++) {
		weight[i][i] = q[i];
		root[i][i] = 0;
		cost[i][i] = 0;
		weight[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
		cost[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
		root[i][i + 1] = i + 1;
	}
	weight[n][n] = q[n];
	root[n][n] = 0;
	cost[n][n] = 0;

	//나머지 행사다리꼴 계산
	int j, k;
	for (int m = 2; m <= n; m++) {
		for (int i = 0; i <= n - m; i++) {
			j = i + m;
			weight[i][j] = weight[i][j - 1] + p[j] + q[j];
			k = knuth_min(cost, root, i, j);	//T[i][j]의 k값을 반환. 최적 루트노드 r[i][j].
			cost[i][j] = weight[i][j] + cost[i][k - 1] + cost[k][j];
			root[i][j] = k;
		}
	}

	printf("\ncost : \n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%2d ", cost[i][j]);
		}
		printf("\n");
	}
	printf("\nroot : \n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%2d ", root[i][j]);
		}
		printf("\n");
	}
	printf("\nweight : \n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%2d ", weight[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	preorder_tree(1, 4, root, 0, 0);
}

int main() {
	int p[MAX_GRAPH_SIZE] = { 0,3,3,1,1 };
	int q[MAX_GRAPH_SIZE] = { 2,3,1,1,1 };
	int cost[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
	int root[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
	int weight[MAX_GRAPH_SIZE][MAX_GRAPH_SIZE];
	int n = 4;
	for (int i = 0; i < MAX_GRAPH_SIZE; i++) {
		for (int j = 0; j < MAX_GRAPH_SIZE; j++) {
			cost[i][j] = -1;
			root[i][j] = -1;
			weight[i][j] = -1;
		}
	}
	op_bin_search(p, q, cost, root, weight, n);

	return 0;
}
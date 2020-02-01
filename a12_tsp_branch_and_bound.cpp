/*
#외판원 문제(TSP) / 분기한정 최고우선 검색
외판원의 집이 위치하고 있는 도시에서 출발하여 다른 도시들을 각각 한번씩 만 방문하고, 
다시 집으로 돌아오는 가장 짧은 일주여행경로(tour)를 결정하는 문제.
이 문제는 음이 아닌 가중치가 있는, 방향성 그래프로 나타낼 수 있다.
그래프 상에서 일주여행경로(tour, Hamiltonian circuits)는 한 정점을 출발하여 다른 모든 정점을 한번씩만 거쳐서
다시 그 정점으로 돌아오는 경로이다.
여러 개의 일주여행경로 중에서 길이가 최소가 되는 경로가 최적일주여행경로(optimal tour)가 된다.
*/
#include<stdio.h>
#include<stdlib.h>
#include "a12_tsp_heap.h"
#define vertics_num 5	
int n = vertics_num;	//정점의 개수
int adj_mat[vertics_num][vertics_num]{	//인접 행렬
	{0,14,4,10,20},
	{14,0,7,8,7},
	{4,5,0,7,16},
	{11,7,9,0,2},
	{18,7,17,4,0},
};

int min_value = INT_MAX;	//최단 거리
int path[vertics_num];	//경로

//유망성 판단
bool promising(int i, int bound) {

	//n-1번째 노드와 처음 노드는 연결되어 있어야 한다.
	if (n - 1 == i && adj_mat[path[0]][i] == 0) {
		return false;
	}
	//전의 정점과 현재 정점은 연결되어 있어야 한다.
	else if (adj_mat[path[i-1]][path[i]] == 0) {
		return false;
	}
	/*for (int j = 0; j < i; j++) {   //정점은 전에 지나온 정점이 될 수 없다.
		if (path[i] == path[j]) {
			return false;
		}
	}*/
	if (bound > min_value) {	//현재 정점의 기댓값 bound가 현재의 최소 거리보다 짧아야 한다.
		return false;
	}

	return true;    //네가지 조건을 모두 만족하면 유망하다고 판단
}

//마디 정보 출력
void print_status(Node u, bool best) {
	if (best) {
		printf("최적해 마디(최단 거리) optimal tour : ");
		printf("<");
		for (int i = 0; i <= n; i++) {
			if (i == n) {
				printf("%d", u.pt[i]);
			}
			else printf("%d,", u.pt[i]);
		}
		printf(">");
	}
	else {
		printf("현재 마디 : ");
		printf("<");
		for (int i = 0; i <= u.i; i++) {
			if (i == u.i) {
				printf("%d", u.pt[i]);
			}
			else printf("%d,", u.pt[i]);
		}
		printf(">");
	}
	if (u.i >= n-2) {
		printf(" value : %d \n", u.bound);
	}
	else printf(" bound : %d \n", u.bound);
}

//bound값 계산
int get_bound(int i, int start) {
	int bound=0;
	int a[vertics_num];	//현재 path에 속하지 않는 정점들의 집합
	int c[vertics_num];	//시작점을 포함한 현재 path에 속하지 않는 정점들의 집합
	int a_num = 0;
	int c_num = 0;

	//현재까지의 경로의 정점들의 distance의 합
	for (int k = 0; k < i; k++) {
		if (k == n-1) {
			break;
		}
		bound += adj_mat[path[k]][path[k + 1]];
	}

	//현재 path에 속하지 않는 정점의 집합 a[] 구하기
	int flag = 0;
	for (int k = 0; k < n; k++) {
		for (int j = 0; j <= i; j++) {
			if (path[j] == k) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			a[a_num++] = k;
		}
		flag = 0;
	}

	//현재 정점에서 a[]에 속하는 정점으로 가는 거리의 최소값(min_d)
	int min_d=9999;
	for (int j = 0; j < a_num; j++) {
		if (min_d > adj_mat[path[i]][a[j]] && path[i]!=a[j]) {
			min_d = adj_mat[path[i]][a[j]];
			flag = 1;
		}
	}
	if (flag == 0) {
		min_d = 0;
	}

	//현재 path에 속하지 않는 정점 + 시작정점의 집합 c[] 구하기
	for (int k = 0; k < a_num; k++) {
		c[c_num] = a[k];
		c_num++;
	}
	c[c_num] = start;
	c_num++;

	//집합 a[]의 각각의 정점에서 c[]에 속하는 정점으로 가는 최솟값(min_v)들의 합 sum_v
	int min_v = INT_MAX;
	int sum_v = 0;
	for (int j = 0; j < a_num; j++) {
		for (int k = 0; k < c_num; k++) {
			if (min_v > adj_mat[a[j]][c[k]] && a[j] != c[k]) {
				min_v = adj_mat[a[j]][c[k]];
			}
		}
		sum_v += min_v;
		min_v = INT_MAX;
	}

	//만약 집합 a[]가 존재하지 않으면 시작점과 이어주어 경로 완성
	if (a_num == 0) {
		bound += adj_mat[path[i]][path[start]];
	}

	bound = bound + min_d + sum_v;	//bound 구하기
	return bound;

}

//TSP 알고리즘
Node tsp_func(int i, int start) {
	Heap* hp = create_heap();	
	Node u = create_node();	//히프에 삽입할 마디(가지뻗기 시도할 마디)
	Node v = create_node();	//히프에서 꺼낼 마디(탐색된 마디)
	Node r = create_node();	//최적해 마디
	u.i = 0;	//수준 초기화
	path[0] = start;	//시작 정점 초기화
	u.bound = get_bound(i, start);	//기댓값 계산
	for (int k = 0; k <= i; k++) {	//힙에 넣기 전에 경로 정보 복사
		u.pt[k] = path[k];
	}
	r = u;	//최선의 경우 저장
	init_heap(hp);
	insert_heap(hp, u);	//힙에 넣음

	//분기 한정법, 최고우선 탐색 시작
	while (hp->heap_size != 0) {
		v = delete_heap(hp);	//heap에서 가장 짧은 bound(distance)의 마디를 꺼낸다.
		print_status(v,0);
		for (int k = 0; k <= v.i; k++) {	//현재 경로에 힙에서 꺼낸 정보를 복사
			path[k] = v.pt[k];
		}
		//n-2 수준에 도달하였으면 경로가 결정되었음. ex) 1-3-4-2 == 1-3-4-2-5-1
		//이 때 min_value보다 bound값이 작을시 갱신
		if (v.i == n - 2 && min_value > v.bound) {
			min_value = v.bound;
			r = v;
		}
		if (i < n-1) {	//최고 수준의 마디까지 도달하지 않았다면
			i = v.i + 1;	//현재 마디에서 가지를 뻗기 위해 수준 증가.
			int flag = 0;
			for (int k = 0; k < n && i < n; k++) {	//다음 경로 k 검사
				for (int j = 0; j < i; j++) {	//k가 이미 지나온 경로라면 가지를 뻗지 않는다.
					if (k == path[j]) {
						flag = 1;
						break;
					}
				}
				if (flag == 0) {	//k가 지나온 경로가 아니라면 가지를 뻗는다.
					path[i] = k;	//경로 설정
					u.i = i;	//bound를 구하고 u에 현재 정보 저장
					u.bound = get_bound(i, start);	
					for (int k = 0; k <= i; k++) {
						u.pt[k] = path[k];
					}
					if (promising(i, u.bound)) {	//현재 마디가 유망하다면
						insert_heap(hp, u);	//힙에 저장
						//printf("enqueue i : %d bound %d min %d \n", u.i, u.bound, min_value);
					}
				}
				else {
					flag = 0;
				}
			}
		}
	}
	free(hp);
	return r;
}

//Node의 미완성 경로 완성 (<1,3,4,2> -> <1,3,4,2,5,1>)
Node path_end(Node r, int start) {
	int flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (r.pt[j] == i) flag = 1;
		}
		if (flag == 0) {
			r.pt[n - 1] = i;
			break;
		}
		flag = 0;
	}
	r.pt[n] = start;
	return r;
}

int main() {
	Node best;
	best = tsp_func(0, 0);
	best = path_end(best, 0);
	print_status(best, 1);
	return 0;
}
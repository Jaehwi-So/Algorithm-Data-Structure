/*
#배낭채우기 문제(분기한정법, 최고우선 탐색)
무게가 한정되어 있는 배낭/ 각각의 무게(weight)와 값어치(profit)가 정해진 item들이 있다.
이 배낭에 최대한으로 값어치 있는 item들을 넣는 방법 찾기
*/
#include <stdio.h>
#include <stdlib.h>
#include "a12_01knapsack_brb_heap.h"

int n = item_num;	//담을 item의 개수
int w[item_num + 10] = { 0,2,5,10,5 };	//item의 무게
int p[item_num + 10] = { 0,40,30,50,10 };	//item의 값어치
int maxWeight = 16;	//최대 배낭 무게
int maxProfit = 0;	//계산된 최대 값어치


//현재 마디의 bound값을 반환
int get_bound(int i, int profit, int weight) {
	int bound;	//bound : 현재 마디에서 앞으로 기대되는 최대 값어치의 기댓값
	int totWeight = weight;	//현재 마디에서 최대로 담을 수 있는 무게의 한계
	int profit_expect = 0;	//현재 마디에서 앞으로 추가할 수 있는 값어치의 한계값
	int k;	//총 무게가 넘는 마디의 수준
	if (i > n + 1) {
		return 0;
	}
	if (weight > maxWeight) {
		return 0;
	}
	//현재 다음 마디 수준부터 무게를 넘지 않고 최대로 담을 수 있는 마디 수준까지
	for (k = i + 1; totWeight + w[k] <= maxWeight && k <= n; k++) {
		profit_expect += p[k];	//값어치의 한계값 갱신
		totWeight += w[k];	//무게의 한계값 갱신
	}
	if (k <= n) {	//총 무게를 넘는 마디 k가 상태공간 트리 수준의 끝을 넘지 않는 경우 -> 남은 수준에 대한 값 계산
		bound = profit + profit_expect + ((maxWeight - totWeight) * (p[k] / w[k])); //bound 계산
	}
	else if (k > n) {	//총 무게를 넘는 마디 k가 상태공간 트리 수준의 끝을 넘는 경우
		bound = profit + profit_expect;
	}

	return bound;
}

//유망성 판단
bool promising(int bound) {
	return bound > maxProfit;	//현재 최대 profit보다 기댓값이 높으면 유망하다.
}

//knapsack 알고리즘
TreeNode knapsack_bab(int i, int weight, int profit) {
	Heap* hp = create_heap();
	TreeNode u, v, r;
	u.weight = weight;
	u.profit = profit;
	u.i = i;
	u.bound = get_bound(u.i, u.profit, u.weight);
	r = u;
	init_heap(hp);
	insert_heap(hp, u);

	//분기 한정법, 최고우선 탐색 시작
	while (hp->heap_size!=0) {
		v = delete_heap(hp);	//heap에서 가장 높은 profit의 가지를 dequeue
		if (maxProfit <= v.profit && v.weight <= maxWeight) {	//최적 profit 갱신
			maxProfit = v.profit;
			r = v;	//최적해 갱신
		}
		printf("현재 마디 : [weight %d, profit %d, bound %d, maxprofit %d]\n", v.weight, v.profit, v.bound, maxProfit);

		/*왼쪽 마디 탐색, item을 포함 시키는 경우*/
		u.i = (v.i) + 1;
		u.weight = (v.weight) + w[u.i];
		u.profit = (v.profit) + p[u.i];
		u.bound = get_bound(u.i, u.profit, u.weight);
		if (promising(u.bound) && u.weight <= maxWeight) {	//유망하다면
			insert_heap(hp, u);//가지 뻗기
		}

		/*오른쪽 마디 탐색, item을 포함 안시키는 경우*/
		u.weight = v.weight;
		u.profit = v.profit;
		u.bound = get_bound(u.i, u.profit, u.weight);
		if (promising(u.bound) && u.weight <= maxWeight) {	//유망하다면
			insert_heap(hp, u);	//가지뻗기
		}
	}

	free(hp);
	return r;
}



int main(void) {
	TreeNode result;
	result = knapsack_bab(0, 0, 0);
	printf("최적 마디 : [weight %d, profit %d, bound %d, maxprofit %d]\n", result.weight, result.profit, result.bound, maxProfit);

	return 0;

}
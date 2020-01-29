/*
#배낭채우기 문제
무게가 한정되어 있는 배낭/ 각각의 무게(weight)와 값어치(profit)가 정해진 item들이 있다.
이 배낭에 최대한으로 값어치 있는 item들을 넣는 방법 찾기
*/
#include <stdio.h>
#include <stdlib.h>

#define item_num 4
int n = item_num;	//담을 item의 개수
int w[item_num + 1] = { 0,2,5,10,5 };	//item의 무게
int p[item_num + 1] = { 0,40,30,50,10 };	//item의 값어치
int maxWeight = 16;	//최대 배낭 무게
int maxProfit = 0;	//계산된 최대 값어치
bool include[item_num + 1]; //해당 item의 포함 여부
bool best_include[item_num + 1];  //최대 값어치일 때의 item 포함여부

//현재 마디의 bound값을 반환
int get_bound(int i, int weight, int profit) {
	int bound;	//bound : 현재 마디에서 앞으로 기대되는 최대 값어치의 기댓값
	int totWeight = weight;	//현재 마디에서 최대로 담을 수 있는 무게의 한계
	int profit_expect = 0;	//현재 마디에서 앞으로 추가할 수 있는 값어치의 한계값
	int k;	//총 무게가 넘는 마디의 수준
	if (weight > maxWeight) {
		return false;
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

//현재 탐색중인 마디의 정보 출력
void print_status(int cur_bound, bool icd[], bool isBest) {
	if (isBest == false) 	printf("현재 마디 : ");
	else printf("최적해 마디 : ");
	int sum_w, sum_p;
	sum_w = sum_p = 0;
	for (int i = 1; i <= n; i++) {
		printf("(item %d) ", i);
		if (icd[i] == true) {
			printf("o ");
			sum_w += w[i];
			sum_p += p[i];
		}
		else {
			printf("x ");
		}
	}
	if (isBest == false) printf("\n[weight : %d, profit %d bound %d]\n", sum_w, sum_p, cur_bound);
	else printf("\n[weight : %d, profit %d]\n", sum_w, sum_p);
	printf("===========================================\n");
}

//knapsack 알고리즘
void knapsack_backtrack(int i, int weight, int profit) {
	int bound = get_bound(i, weight, profit);
	print_status(bound, include, false);
	if (maxProfit <= profit && weight <= maxWeight) {	//최대 profit과 그 경우의 item 포함여부 갱신
		maxProfit = profit;
		for (int i = 1; i <= n; i++) {
			best_include[i] = include[i];
		}
	}
	if (promising(bound)) {	//현재 마디가 유망하다면
		include[i + 1] = true;	//트리에서의 왼쪽. 다음 마디의 item을 포함
		knapsack_backtrack(i + 1, weight + w[i + 1], profit + p[i + 1]);
		include[i + 1] = false;	//트리에서의 오른쪽. 다음 마디의 item을 포함안함.
		knapsack_backtrack(i + 1, weight, profit);
	}
}

int main(void) {
	knapsack_backtrack(0, 0, 0);
	print_status(maxProfit, best_include, true);
	return 0;
}
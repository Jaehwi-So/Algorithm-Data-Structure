/*
부분집합의 합 구하기 문제.
집합 w로부터 부분집합을 만들어 합이 정수 W가 되게 하는 경우의 수 출력
부분집합에 포함된 정수와 인덱스를 포함하여 출력.
*/
#include <stdio.h>
#include <stdlib.h>

int n = 6;
int w[] = { 0, 2, 10, 13, 17, 22, 42 };
int W = 52;
bool include[7]; //해당 item의 포함 여부

bool promising(int i, int weight, int total) {  //현재 마디수준 i, 현재 무게 weight, 남은 item들의 무게의 합 total
	return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
	//현재 무게+남은 무게가 W보다 크고 // 현재 무게가 W와 같거나 || 현재 무게+다음 마디 무게가 W보다 작을 경우
	//(weight<W && weight+w[i+1]>W) || weight+total<W)인 경우 유망하지 않음
	//현재 무게+남은 무게가 W보다 작거나 현재 무게가 W보다 작으나 && 다음 마디에서 커지는 경우
}
void sum_of_subset(int i, int weight, int total) {
	if (promising(i, weight, total)) {	//현재 마디가 유망하다면
		if (weight == W) {	//이 때 만약 배낭의 무게와 짐들의 총 무게가 같다면
			for (int j = 0; j <= i; j++) {	//부분집합 출력
				if (include[j]) {		//포함된 마디의 item을 출력
					printf("item %d(i=%d) ", w[j], j);
				}
			}
			printf("\n");
		}
		else {	//현재 마디가 유망하나 아직 답을 찾지 못한 경우
			include[i + 1] = true;	//트리에서의 왼쪽. 다음 마디의 w를 포함
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			//(/다음 마디/, /현재 무게 + 다음 마디의 무게/, /모든 짐의 총 무게-현재까지의 무게(=남은 아이템들의 무게)/)
			include[i + 1] = false;	//트리에서의 오른쪽. 다음 마디의 w를 포함 x
			sum_of_subset(i + 1, weight, total - w[i + 1]);
		}
	}

}

int main(void) {
	int total = 0;
	for (int i = 1; i <= 6; i++) {
		total += w[i];
	}
	sum_of_subset(0, 0, total);
	return 0;
}

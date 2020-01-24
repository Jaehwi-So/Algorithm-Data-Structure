/*
#칵테일 셰이커 정렬(Cocktail Shaker Sort / Bidirection Bubble Sort), 양방향 버블 정렬
정렬이 최근에 이루어진 부분을 기준으로 스캔 범위를 제한하여 정렬하면서
한번의 정렬과정 후 정렬 방향을 교대하면서 정렬한다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 8
#define swap(X,Y,T) T=X; X=Y; Y=T

//배열 초기화
void init_array(int array[]) {
	srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		array[i] = rand() % 50 + 1;
	}
}

//배열 출력
void print_set(int S[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", S[i]);
	}
	printf("\n");
}

//버블 정렬
void bid_bubble_sort(int S[], int n) {
	int tmp;
	int idx_f = 0; //idx_f 앞쪽은 정렬 완료된 상태
	int idx_b = n-1; //idx_b 뒤쪽은 정렬 완료된 상태
	int flag = 0; //0일시 앞쪽부터 정렬, 1일시 뒤쪽부터 정렬
	int ck;
	while (idx_f != idx_b) { //idx_f == idx ==b이면 정렬완료인 상태
		if (flag == 0) { //flag가 0일 시 앞쪽부터 정렬
			ck = n - 1;
			for (int j = idx_b; j > idx_f; j--) //뒤쪽의 정렬 완료된 부분부터 앞쪽의 정렬 완료된 부분까지 정렬 패스
				if (S[j - 1] > S[j]) {
					swap(S[j - 1], S[j], tmp);
					ck = j;
				}
			idx_f = ck;
			flag = 1; //교대
		}
		else if (flag == 1) {//flag가 1일 시 뒤쪽부터 정렬
			ck = 1;
			for (int j = idx_f; j < idx_b; j++) //앞쪽의 정렬 완료된 부분부터 뒤쪽의 정렬 완료된 부분까지 정렬 패스
				if (S[j] > S[j+1]) {
					swap(S[j + 1], S[j], tmp);
					ck = j;
				}
			idx_b = ck;
			flag = 0; //교대
		}
		print_set(S);
	}
}

int main() {
	int array[MAX_SIZE];
	init_array(array);
	bid_bubble_sort(array, MAX_SIZE);
	return 0;
}
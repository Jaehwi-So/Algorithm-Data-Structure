/*
#버블 정렬(Bubble Sort)(향상)
정렬이 최근에 이루어진 부분을 기준으로 스캔 범위를 제한하여 정렬한다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
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
void bubble_sort(int S[], int n) {
	int tmp;
	int idx = 0; //idx 앞쪽은 정렬 완료된 상태

	while (idx < n - 1) {
		int j;
		int ck = n - 1; //교환을 마지막으로 한 시점을 체크해두어 
		//이 지점보다 앞의 수들은 정렬이 완료되었음을 가정하고 연산하지 않는다.
		for (j = n - 1; j > idx; j--)
			if (S[j - 1] > S[j]) {
				swap(S[j - 1], S[j], tmp);
				ck = j;
			}
		idx = ck;
		print_set(S);
	}
}
int main() {
	int array[MAX_SIZE];
	init_array(array);
	bubble_sort(array, MAX_SIZE);
	return 0;
}
//#삽입 정렬(Insertion Sort)
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

//삽입 정렬
void insertion_sort(int S[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = S[i]; //정렬할 레코드

		//이미 정렬된 부분을 비교하여 key보다 작은 레코드가 나올 때까지 스캔
		for (j = i; j > 0 && S[j-1] > key; j--) { 
			S[j] = S[j - 1];	//하나씩 우측으로 이동
		}
		S[j] = key;	//작은 레코드가 발견되면 해당 자리에 key를 삽입
		print_set(S);
	}
}
int main() {
	int array[MAX_SIZE];
	init_array(array);
	insertion_sort(array, MAX_SIZE);
	return 0;
}
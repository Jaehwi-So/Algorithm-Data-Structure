//#버블 정렬
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define swap(X,Y,T) T=X; X=Y; Y=T

//배열 초기화
void init_array(int array[]) {
    srand((unsigned)time(NULL));
	for (int i = 0; i < MAX_SIZE; i++) {
		array[i]= rand() % 50 + 1;
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
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (S[j] < S[j - 1]) {
				swap(S[j], S[j - 1], tmp);	// 앞뒤의 수를 비교 후 교환
			}
		}
		print_set(S);
	}
}
int main() {
	int array[MAX_SIZE];
	init_array(array);
	bubble_sort(array, MAX_SIZE);
	return 0;


}
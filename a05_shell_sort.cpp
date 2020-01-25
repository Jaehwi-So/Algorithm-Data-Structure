//#셸 정렬(Shell Sort)
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

//셸 정렬
void shell_sort(int S[], int n) {
	int h, key;
	for (int i = n; i > 0; i /= 2) {	//i=증분값, i-정렬을 통해서 정렬에 가깝게 함
		for (int j = i; j < n; j++) {	//삽입 정렬
			key = S[j];
			for (h = j - i; h >= 0 && S[h] > key; h -= i) {
				S[h + i] = S[h];
			}
			S[h + i] = key;
		}
		print_set(S);
	}
	

}
int main() {
	int array[MAX_SIZE];
	init_array(array);
	shell_sort(array, MAX_SIZE);
	return 0;
}
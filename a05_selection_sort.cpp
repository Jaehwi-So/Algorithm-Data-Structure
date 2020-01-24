//#선택 정렬(Selection Sort)
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

//선택 정렬
void selection_sort(int S[], int n) {
	int temp;
	for (int i = 0; i < n-1; i++) { //앞쪽부터 정렬
		int min = i; //최솟값
		for (int j = i + 1; j < n; j++) { //정렬이 완료 안된 부분부터 스캔하여
			if (S[j] < S[min]) { //만약 현재 최솟값보다 작은 수가 있다면
				min = j;	//최솟값 갱신
			}
		}
		swap(S[i], S[min], temp);	//최솟값을 앞으로 보낸다.
		print_set(S);
	}

}
int main() {
	int array[MAX_SIZE];
	init_array(array);
	selection_sort(array, MAX_SIZE);
	return 0;
}
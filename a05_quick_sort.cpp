//#퀵 정렬(Quick Sort)
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

int partition(int S[], int left, int right) {
	int pivot, temp;	//pivot : 왼쪽에는 pivot보다 작은 값이 오도록, 오른쪽에는 pivot보다 큰 값이 오도록 정렬할 것이다.
	int low, high;
	low = left;
	high = right + 1;
	pivot = S[left];
	do {
		do { low++; } while (low <= right && S[low] < pivot); //low index가 배열의 끝까지 가지 않았고 pivot보다 큰 값을 만날 때까지 low 증가
		do { high--; } while (high >= left && S[high] > pivot);//high index가 배열의 시작까지 가지 않았고 pivot보다 작은 값을 만날 때까지 high증가
		if (low < high) {
			swap(S[low], S[high], temp); //조건검사할 배열의 element가 아직 남아 있다면 위에서 잡아낸 low index와 high index를 swap
		}
	} while (low < high);//조건검사할 배열의 element가 1개 이상 남아있는 경우	 
	swap(S[left], S[high], temp); //최종적인 pivot이 들어갈 위치에 pivot을 집어넣는다.
	print_set(S);
	return high;
}

void quick_sort(int S[], int left, int right) {
	if (left < right) {
		int q = partition(S, left, right);
		quick_sort(S, left, q - 1);   //pivot을 기준으로 분할 정복법을 이용하여 정렬
		quick_sort(S, q + 1, right);
	}
}

int main() {
	int array[MAX_SIZE];
	init_array(array);
	quick_sort(array, 0, MAX_SIZE-1);
	return 0;
}

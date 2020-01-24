/*
문제 :퀵 정렬 과정을 최소화하여 배열의 모든 element를 정렬하지 않고 최소한으로 정렬하여 Median값을 얻어내시오
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 15
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

//Partition
int partition(int S[], int left, int right) {
	int pivot, temp;
	int low, high;
	int q;
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

//퀵 정렬
int quick_sort(int S[], int left, int right, int median) {
	int pivot;
	do {
		pivot = partition(S, left, right);    //partiton 진행 후 pivot값 결정
		if (pivot > median) {	//pivot index가 median보다 크다면 왼쪽 배열을 재정렬 하기 위해서 right를 pivot-1로 설정
			right = pivot - 1;
		}
		else if (pivot < median) {	//pivot index가 median보다 크다면 오른쪽 배열을 재정렬 하기 위해서 left를 pivot+1로 설정
			left = pivot + 1;
		}
	} while (pivot != median);
	return S[pivot];	//pivot index가 median과 일치시 값 반환 == 정렬 완료. median 값을 구했음
}

int main() {
	int array[MAX_SIZE];
	init_array(array);
	printf("quick sort :: median element : %d \n", quick_sort(array, 0, MAX_SIZE - 1, (MAX_SIZE - 1) / 2));   //
	return 0;
}


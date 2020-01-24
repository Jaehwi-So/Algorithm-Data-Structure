//#합병 정렬(Merge Sort)
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
void print_set(int S[], int left, int right) {
	for (int i = left; i <= right; i++) {
		printf("[%d:%d]", i, S[i]);
	}
	printf("\n");
}

//합병
void merge(int S[], int left, int right, int mid) {
	int i = left;	//합병할 왼쪽 배열의 index
	int j = mid + 1;	//합병할 오른쪽 배열의 index
	int k = left; //새로운 배열에 차례로 정렬하여 채우기 위한 index
	int l;	
	int buf[MAX_SIZE]; //정렬되는 배열을 저장할 임시공간

	while (i <= mid && j <= right) {	//i와 j가 둘 다 끝가지 도달하지 않았다면
		if (S[i] <= S[j]) {	//왼쪽 배열의 레코드가 오른쪽 배열의 레코드보다 작다면
			buf[k++] = S[i++];	//왼쪽 배열의 레코드를 복사 후 왼쪽 배열의 index증가
		}
		else {
			buf[k++] = S[j++]; //오른쪽 배열의 레코드를 복사 후 오른쪽 배열의 index증가
		}
	}

	//남아있는 레코드들의 복사
	if (i > mid) {
		for (l = j; l <= right; l++) {
			buf[k++] = S[l];
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			buf[k++] = S[l];
		}
	}

	//다시 원래 배열에 복사
	for (l = left; l <= right; l++) {
		S[l] = buf[l];
	}


}

//합병 정렬
void merge_sort(int S[], int left, int right) {

	int i;
	int mid;
	printf("분할 : ");
	print_set(S, left, right);
	if (left < right) {		//분할이 가능하다면
		mid = ((left + right) / 2);
		merge_sort(S, left, mid);	//왼쪽 분할
		merge_sort(S, mid + 1, right);	//오른쪽 분할
		merge(S, left, right, mid);		//합병
	}
	printf("합병 : ");
	print_set(S, left, right);
}



int main() {
	int array[MAX_SIZE];
	init_array(array);
	merge_sort(array, 0, MAX_SIZE-1);
	return 0;
}
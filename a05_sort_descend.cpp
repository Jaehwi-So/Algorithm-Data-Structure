/*
함수 포인터를 이용하여 삽입 정렬(insertion_sort) 과정을 오름차순, 내림차순으로 정렬하기
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define swap(X,Y,T) T=X; X=Y; Y=T
#define TRUE 1
#define FALSE 0
int ascend(int x, int y);
int descend(int x, int y);


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
void insertion_sort(int S[], int n, int(*f)(int, int)) {
	int i, j, key;
	//이미 정렬된 부분을 key값과 비교
	for (i = 1; i < n; i++) {
		key = S[i]; //정렬할 레코드
		//스캔하는 레코드와 key값을 비교하여 전달받은 함수 유형에 따라서 정렬
		for (j = i - 1; j >= 0 && f(S[j], key); j--)
			S[j + 1] = S[j]; //하나씩 우측으로 이동
		S[j + 1] = key;//해당 자리에 key를 삽입
		print_set(S);
	}
}

int main() {
	int array[MAX_SIZE];
	init_array(array);
	printf("------ascend sort---------------\n");
	insertion_sort(array, MAX_SIZE, ascend);
	printf("------descend sort--------------\n");
	insertion_sort(array, MAX_SIZE, descend);
	return 0;
}

//오름차순일 경우의 조건
int ascend(int x, int y)
{
	if (x > y) return TRUE;
	else return FALSE;
}

//내림차순일 경우의 조건
int descend(int x, int y)
{
	if (x < y) return TRUE;
	else return FALSE;
}
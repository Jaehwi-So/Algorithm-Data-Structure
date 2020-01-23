//#6 정수 n을 입력받아 크기 n 의 배열을 생성하여 역순으로 정렬
#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y,t) t=x; x=y; y=t; //두 정수 교환 swap 정의

//역순 정렬 함수
void sort_array(int array[], int size) {
	int temp = 0;
	for (int i = 0; i < size / 2; i++) {
		SWAP(array[i], array[size - i], temp);
	}
}

int main() {
	int size=0;
	int number;
	int* array;
	printf("배열의 크기 입력 : ");
	scanf("%d", &size);
	array = (int*)malloc(sizeof(int) * size); //배열 동적할당
	for (int i = 0; i <= size - 1; i++) {
		printf("%d번째 요소 입력 ",i+1);
		scanf("%d", &array[i]);
	}
	sort_array(array, size-1);

	for (int i = 0; i <= size - 1; i++) {
		printf("%d ", array[i]);
	}
}
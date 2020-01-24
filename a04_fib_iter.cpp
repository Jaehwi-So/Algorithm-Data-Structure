/*
피보나치 수열의 n번째 수 구하기(반복)
입력 : 정수 n, 출력 : n번째 수 X
*/
#include<stdio.h>
#include<stdlib.h>

int* fib_arr;//수열을 저장할 배열. 

int get_fib(int n) {
	fib_arr[0] = 0;
	fib_arr[1] = 1;
	for (int i = 2; i <= n; i++) { //반복을 이용하여 중복항을 계산하지 않아 순환보다 효율이 좋다.
		fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2];
	}
	return fib_arr[n];

}
int main() {
	int num = 0;
	printf("n번째 수를 입력해주세요 ");
	scanf("%d", &num);
	fib_arr = (int*)malloc(sizeof(int)*num+1);
	printf("피보나치 연산 결과 : %d", get_fib(num));
	return 0;
}
/*
반복을 사용하여 정수 n의 팩토리얼 구하기
*/
#include<stdio.h>
int get_factorial(int n) {
	int sum=1;
	for (int i = 1; i <= n; i++) {
		sum *= i;
	}
	return sum;
}
int main() {
	printf("팩토리얼 연산 결과 : %d", get_factorial(5));
	return 0;
}
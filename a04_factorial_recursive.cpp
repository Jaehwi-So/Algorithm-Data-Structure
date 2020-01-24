/*
재귀 방식(recursive)를 사용하여 정수 n의 팩토리얼 구하기
*/
#include<stdio.h>
int get_factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	return get_factorial(n - 1) * n;
}
int main() {
	printf("팩토리얼 연산 결과 : %d",get_factorial(5));
	return 0;
}
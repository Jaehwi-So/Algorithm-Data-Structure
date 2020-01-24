/*
피보나치 수열의 n번째 수 구하기(순환)
입력 : 정수 n, 출력 : n번째 수 X
*/
#include<stdio.h>
int get_fib(int n) {
	if (n <= 1) {
		return n;
	}
	return get_fib(n - 2) + get_fib(n - 1);

}
int main() {
	int num = 0;
	printf("n번째 수를 입력해주세요 ");
	scanf("%d", &num);
	printf("피보나치 연산 결과 : %d", get_fib(num));
	return 0;
}
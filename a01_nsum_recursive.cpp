//#4. 1부터 n까지의 합 구하기 (순환)
#include<stdio.h>
int getSum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + getSum(n - 1);
	}
}

int main() {
	int num;
	printf("정수 n 입력 : ");
	scanf_s("%d", &num);
	printf("1부터 %d까지의 합 : %d", num, getSum(num));
	return 0;
}
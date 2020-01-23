//#3. 1부터 n까지의 합 구하기 (반복)
#include<stdio.h>
int getSum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int main() {
	int num;
	printf("정수 n 입력 : ");
	scanf_s("%d", &num);
	printf("1부터 %d까지의 합 : %d", num, getSum(num));
	return 0;
}
//#5 정수 n을 입력받아 n*n크기의 직각 이등변 삼각형 출력하기
/*      출력예시(n=3)
		  *
		 **
		***
*/
#include<stdio.h>
void printTriangle(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = n; j > i; j--) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		printf("\n");
	}
}
int main() {
	int n;
	printf("정수 n을 입력하시오");
	scanf("%d", &n);
	printTriangle(n);
	return 0;
}
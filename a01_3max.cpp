//#2. 세 정수를 입력받아 중간값 구하기
#include<stdio.h>

int main() {
	int num[3];
	printf("정수 세 개 입력 : ");
	scanf("%d %d %d", num, num+1, num+2);
	int max = num[0];
	for (int i = 0; i < 3; i++) {
		if (max < num[i]) {
			max = num[i];
		}
	}
	printf("max : %d", max);
	return 0;
}
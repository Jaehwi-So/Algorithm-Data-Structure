//#2. 세 정수를 입력받아 중간값 구하기
//조건 판단과 분기
#include<stdio.h>
int getMed(int num1, int num2, int num3) {
	if (num1 >= num2)
		if (num2 >= num3)
			return num2;
		else if (num1 <= num3)
			return num1;
		else
			return num3;
	else if (num1 > num3)
		return num1;
	else if (num2 > num3)
		return num3;
	else
		return num2;
}
int main() {
	int num[3];
	int med;
	printf("세 정수 입력 : ");
	scanf("%d %d %d", num, num + 1, num + 2);
	med = getMed(num[0], num[1], num[2]);
	printf("medium : %d", med);
	return 0;
}
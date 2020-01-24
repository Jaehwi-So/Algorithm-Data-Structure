/*
문제 : 유클리드 호제법을 이용하여 두개의 정수 x, y에 대한 최대공약수 구하기
입력 : 정수 X, Y / 출력 : 최대공약수 T
*/
#include<stdio.h>
int get_greatest_cd(int x, int y) {
	if (y==0) {
		return x;
	}
	else {
		get_greatest_cd(y, x % y); 
	}
}
int main() {
	int x, y, t;
	printf("두개의 정수 입력 : ");
	scanf("%d %d",&x ,&y);
	t = get_greatest_cd(x, y);
	printf("최대공약수 결과 : %d", t);
	return 0;
}
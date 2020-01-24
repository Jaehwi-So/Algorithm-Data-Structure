/*
하노이의 탑 문제
입력 : 원반 개수 n, 이동 시마다 결과 출력
*/
#include<stdio.h>

void move(int n, char from, char temp, char to) {
	if (n == 1) {
		printf("원판 1 : %c -> %c\n", from, to);
	}
	else {
		move(n - 1, from, to, temp);
		printf("원판 %d : %c -> %c\n", n, from, to);
		move(n - 1, temp, from, to);
	}
}
int main() {
	move(4, 'A', 'B', 'C');
	return 0;
}
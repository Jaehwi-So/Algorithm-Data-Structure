/*순차 탐색(보초법 이용)
보초법을 이용하여 종료 조건의 비용을 반으로 줄일 수 있다.
문제: 크기가 n인 정렬된 배열 S에 x가 있는가?
입력: (1) 양수 n, (2) 배열 S[1..n], (3) 키 x
출력: x가 S의 어디에 있는지의 위치. 만약 없으면, -1.
*/
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define n    19
int S[n] = {0,3,4,6,7,9,11,13,14,15,16,19,20,50,61,72,89,96,-1}; //배열의 마지막은 보초역할

int search_seq(int S[], int x) {
	S[n-1] = x;
	int sq = 0;
	while (1) {
		if (S[sq] == x) {
			return sq;
		}
		sq++;
	}
	return -1;
}

void printSequentialSearch(int S[], int x) {
	if (search_seq(S, x) != -1 && search_seq(S, x) != n-1) {
		printf("보초법 순차 탐색 시작 : key : %d, result : index %d\n", x, search_seq(S, x));
	}
	else {
		printf("보초법 순차 탐색 시작 : key : %d, result : ERROR\n", x);
	}
}
int main() {
	printSequentialSearch(S, 11);
	printSequentialSearch(S, 14);
	printSequentialSearch(S, 35);
	printSequentialSearch(S, 96);
	printSequentialSearch(S, 54);
	return 0;
}
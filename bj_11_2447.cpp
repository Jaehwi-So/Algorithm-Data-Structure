/*백준_2447
문제
재귀적인 패턴으로 별을 찍어 보자.N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 
크기 N의 패턴은 N×N 정사각형 모양이다.
크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
***
* *
***
N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의(N / 3)×(N / 3) 
정사각형을 크기 N / 3의 패턴으로 둘러싼 형태이다.예를 들어 크기 27의 패턴은 예제 출력 1과 같다.
입력
첫째 줄에 N이 주어진다.N은 3의 거듭제곱이다.즉 어떤 정수 k에 대해 N = 3^k이며, 이때 1 ≤ k < 8이다.
출력
첫째 줄부터 N번째 줄까지 별을 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>

int** arr;

//배열 초기화
int** init_mat(int n) {
	int** mat;
	mat = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 0;
		}
	}
	return mat;
}

void put_star(int x1, int y1, int x2, int y2) {
	int bound1 = ((x2 - x1 + 1) / 3);	//경계1
	int bound2 = (((x2 - x1 + 1) / 3)) * 2;	//경계2

	//해당 구역의 크기가 1일 때, *을 찍어줌.
	if (bound1 < 1) {
		arr[x1][y1] = 1;
		return;
	}
	else {
		/* 
		배열을 경계를 통해서 구역을 9부분으로 나누어 분할 정복한다.
		1구역 2구역 3구역
		4구역 5구역 6구역
		7구역 8구역 9구역
		*/
		put_star(x1, y1, (x1 + bound1) - 1, (y1 + bound1) - 1);	//1구역
		put_star(x1 + bound1, y1, (x1 + bound2) - 1, (y1 + bound1) - 1); //2구역
		put_star(x1 + bound2, y1, x2, (y1 + bound1) - 1); //3구역

		put_star(x1, y1 + bound1, (x1 + bound1) - 1, (y1 + bound2) - 1); //4구역
		//5구역은 별을 찍지 않으므로 비운다.
		put_star(x1 + bound2, y1 + bound1, x2, (y1 + bound2) - 1); //6구역

		put_star(x1, y1 + bound2, (x1 + bound1) - 1, y2); //7구역
		put_star(x1 + bound1, y1 + bound2, (x1 + bound2) - 1, y2); //8구역
		put_star(x1 + bound2, y1 + bound2, x2, y2); //9구역
	}
	return;
}
void print_star(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] == 1) {
				printf("*");
			}
			else printf(" ");
		}
		printf("\n");
	}
}
int main() {
	int n = 0;
	scanf("%d", &n);
	arr = init_mat(n);	//배열의 동적할당
	put_star(0, 0, n-1, n-1);
	print_star(n);
	return 0;
}
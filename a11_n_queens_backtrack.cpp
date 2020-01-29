/*
n-queen의 문제.
n*n 체스판에서 퀸을 배치하는 방법. 각각의 퀸의 행, 열, 대각선으로 다른 퀸이 배치되어서는 안된다.
*/
#include<stdio.h>
#include<stdlib.h>
int* queen;
bool* flag_ro; //해당 행의 사용가능 여부
bool* flag_dl; //왼쪽으로 가는 대각선(/) 사용가능 여부
bool* flag_dr; //오른쪽으로 가는 대각선(\) 사용가능 여부

void printQueen(int num) {
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= num; j++) {
			if (j == queen[i]) {
				printf("q");
			}
			else printf("*");
		}
		printf("\n");
	}
	printf("\n");
}

//유망성 판단
bool promising(int row, int co, int num) {
	return !flag_ro[row] && !flag_dl[row + co] && !flag_dr[co - row + num];
	//해당 행, 왼쪽 대각선, 오른쪽 대각선도 사용이 가능하다면(유망하다면) true
}
void queenSet(int num, int co) { //열
	for (int row = 0; row <= num; row++) { //해당 열의 모든 행에 queen 놓기 시도	
		if (promising(row,co,num)) {//해당 행이 유망하다면
			if (co == num) { //모든 열에 배치를 마침. -> 해 하나를 찾음
				printQueen(num); 
				return;
			}
			else {
				queen[co] = row; //가지치기. 
				flag_ro[row] = 1;	//퀸 배치. 해당 행,대각선들을 사용 불가능 표시
				flag_dl[row+co] = 1;
				flag_dr[co-row+num] = 1;

				//다음 열에 배치를 위해서 가지치기 시도
				queenSet(num, co + 1); 
				//Backtracking

				flag_ro[row] = 0;
				flag_dl[row + co] = 0;
				flag_dr[co - row + num] = 0; //Backtracking시 퀸 제거
			}
		}
	}
}

int main() {
	int queenNum=0;
	printf("배치할 퀸의 수를 입력하세요(4이상, 10미만 권장) : ");
	scanf("%d", &queenNum);

	//배열들 동적할당
	queen = (int*)malloc(sizeof(int) * queenNum);
	flag_ro = (bool*)malloc(sizeof(bool) * queenNum);
	flag_dl = (bool*)malloc(sizeof(bool) * queenNum*2-1);
	flag_dr = (bool*)malloc(sizeof(bool) * queenNum * 2 - 1);

	for (int i = 0; i < queenNum; i++) {
		flag_ro[i] = 0;
		queen[i] = 0;
	}

	for (int i = 0; i < queenNum*2-1; i++) {
		flag_dl[i] = 0;
		flag_dr[i] = 0;
	}
	queenSet(queenNum-1, 0);
	return 0;
}
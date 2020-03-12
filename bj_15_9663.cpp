/*bj_9663
문제
N - Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)
출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>

//n x n 체스판에서 한 방향으로 가는 대각선(/ & \)은 각각 n*2-1개가 존재한다.
bool* ck_ro; //행의 방문표시 : 크기 n
bool* ck_diag_l; //왼쪽 대각선 방문표시	: 크기 n*2-1
bool* ck_diag_r; //오른쪽 대각선 방문표시 : 크기 n*2-1
int ck = 0;	//경우의 수


void set_queen(int num, int co) {
	for (int row = 0; row <= num; row++) { //해당 열의 모든 행에 queen 놓기 시도	

		//왼쪽 대각선의 index는 row+co이며 오른쪽 대각선의 index는 co-row+num으로 해당 대각선의 index를 찾을 수 있다.

		//해당 행이 유망하다면(해당 행과 왼쪽 대각선, 오른쪽 대각선 모두 사용중이 아니다. == 퀸이 배치되지 않았다)
		if (!ck_ro[row] && !ck_diag_l[row + co] && !ck_diag_r[co - row + num]) {
			if (co == num) { //배치 완료 -> 해 하나를 찾음
				ck++;
			}
			else {
				ck_ro[row] = 1;	//퀸 배치. 해당 행,대각선들을 사용 불가능 표시
				ck_diag_l[row + co] = 1;
				ck_diag_r[co - row + num] = 1;

				//가지치기
				set_queen(num, co + 1);
				//백트래킹

				ck_ro[row] = 0;
				ck_diag_l[row + co] = 0;
				ck_diag_r[co - row + num] = 0; //백트래킹시 퀸 제거(방문 표시를 지워준다)
			}
		}
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);

	//배열들 동적할당
	ck_ro = (bool*)malloc(sizeof(bool) * n);
	ck_diag_l = (bool*)malloc(sizeof(bool) * n * 2 - 1);
	ck_diag_r = (bool*)malloc(sizeof(bool) * n * 2 - 1);

	for (int i = 0; i < n; i++) {
		ck_ro[i] = 0;
	}

	for (int i = 0; i < n * 2 - 1; i++) {
		ck_diag_l[i] = 0;
		ck_diag_r[i] = 0;
	}
	set_queen(n - 1, 0);
	printf("%d", ck);
	free(ck_ro);
	free(ck_diag_l);
	free(ck_diag_r);
	return 0;
}
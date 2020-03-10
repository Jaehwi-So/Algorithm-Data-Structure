/*bj_11650
문제
2차원 평면 위의 점 N개가 주어진다.좌표를 x좌표가 증가하는 순으로,
x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 점의 개수 N(1 ≤ N ≤ 100, 000)이 주어진다.
둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.
(-100, 000 ≤ xi, yi ≤ 100, 000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
*/

#include<stdio.h>
#include<stdlib.h>

bool compare(int S1[], int S2[]) {
	if (S1[0] < S2[0]) {
		return false;
	}
	else if (S1[0] > S2[0]) {
		return true;
	}
	else if (S1[0] == S2[0] && S1[1] > S2[1]) {
		return true;
	}
	return false;
}

void insertion_sort(int(*S)[2], int n) {
	int i, j;
	int key[2];
	for (i = 1; i < n; i++) {
		//정렬할 레코드
		key[0] = S[i][0];
		key[1] = S[i][1];
		//이미 정렬된 부분을 비교하여 key보다 큰 레코드가 나올 때까지 스캔
		for (j = i; j > 0 && compare(S[j - 1], key); j--) {
			S[j][0] = S[j - 1][0];	//하나씩 우측으로 이동
			S[j][1] = S[j - 1][1];
		}
		S[j][0] = key[0];	//큰 레코드가 발견되면 해당 자리에 key를 삽입
		S[j][1] = key[1];
	}
	for (int k = 0; k < n; k++) {
		printf("%d %d\n", S[k][0], S[k][1]);
	}
}

int main() {
	int n;
	int point[100000][2];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point[i][0], &point[i][1]);
	}
	insertion_sort(point, n);
	return 0;
}


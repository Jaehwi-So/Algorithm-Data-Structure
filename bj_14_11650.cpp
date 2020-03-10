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
#define swap(X,Y,T) T=X; X=Y; Y=T

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

int partition(int(*S)[2], int left, int right) {
    int temp;
	int pivot[2];	//pivot : 왼쪽에는 pivot보다 작은 값이 오도록, 오른쪽에는 pivot보다 큰 값이 오도록 정렬할 것이다.
	int low, high;
	low = left;
	high = right + 1;
	pivot[0] = S[left][0];
	pivot[1] = S[left][1];
	do {
		do { low++; } while (low <= right && compare(pivot, S[low])); //low index가 배열의 끝까지 가지 않았고 pivot보다 큰 값을 만날 때까지 low 증가
		do { high--; } while (high >= left && compare(S[high], pivot));//high index가 배열의 시작까지 가지 않았고 pivot보다 작은 값을 만날 때까지 high증가
		if (low < high) {
			swap(S[low][0], S[high][0], temp); //조건검사할 배열의 element가 아직 남아 있다면 위에서 잡아낸 low index와 high index를 swap
			swap(S[low][1], S[high][1], temp);
		}
	} while (low < high);//조건검사할 배열의 element가 1개 이상 남아있는 경우	 
	swap(S[left][0], S[high][0], temp); //최종적인 pivot이 들어갈 위치에 pivot을 집어넣는다.
	swap(S[left][1], S[high][1], temp); //최종적인 pivot이 들어갈 위치에 pivot을 집어넣는다.
	return high;
}

void quick_sort(int (*S)[2], int left, int right, bool start) {
	if (left < right) {
		int q = partition(S, left, right);
		quick_sort(S, left, q - 1, false);   //pivot을 기준으로 분할 정복법을 이용하여 정렬
		quick_sort(S, q + 1, right, false);
	}
	if (start == true) {
		for (int k = 0; k <= right; k++) {
			printf("%d %d\n", S[k][0], S[k][1]);
		}
	}
}

int main() {
	int n;
	int point[100000][2];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point[i][0], &point[i][1]);
	}
	//insertion_sort(point, n);
	quick_sort(point, 0, n - 1, true);
	return 0;
}


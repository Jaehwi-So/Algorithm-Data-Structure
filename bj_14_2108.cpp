/*bj_14_2108
문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 
다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.
산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 
입력되는 정수의 절댓값은 4,000을 넘지 않는다.
출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
둘째 줄에는 중앙값을 출력한다.
셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
넷째 줄에는 범위를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>
#define swap(X,Y,T) T=X; X=Y; Y=T
int arr[500000];
int freq[8001][2];
int mode[8001];

/*   퀵 정렬    */
int partition(int S[], int left, int right) {
	int pivot, temp;	//pivot : 왼쪽에는 pivot보다 작은 값이 오도록, 오른쪽에는 pivot보다 큰 값이 오도록 정렬할 것이다.
	int low, high;
	low = left;
	high = right + 1;
	pivot = S[left];
	do {
		do { low++; } while (low <= right && S[low] < pivot); //low index가 배열의 끝까지 가지 않았고 pivot보다 큰 값을 만날 때까지 low 증가
		do { high--; } while (high >= left && S[high] > pivot);//high index가 배열의 시작까지 가지 않았고 pivot보다 작은 값을 만날 때까지 high증가
		if (low < high) {
			swap(S[low], S[high], temp); //조건검사할 배열의 element가 아직 남아 있다면 위에서 잡아낸 low index와 high index를 swap
		}
	} while (low < high);//조건검사할 배열의 element가 1개 이상 남아있는 경우	 
	swap(S[left], S[high], temp); //최종적인 pivot이 들어갈 위치에 pivot을 집어넣는다.
	return high;
}

/*   퀵 정렬    */
void quick_sort(int S[], int left, int right) {
	if (left < right) {
		int q = partition(S, left, right);
		quick_sort(S, left, q - 1);   //pivot을 기준으로 분할 정복법을 이용하여 정렬
		quick_sort(S, q + 1, right);
	}
}

/*   산술평균    */
double arithmetic_mean(int S[], int n) {
	if (n == 0) {
		return 0;
	}
	double sum = 0;
	for (int i = 0; i < n; i++) {	//수를 모두 더한 후 n으로 나눈다.
		sum += S[i];
	}
	sum /= n;
	return sum;
}

/*   최빈값    */
int get_mode(int S[], int n) {
	int i, j;
	//freq[i][0] : 정수의 빈도수, freq[i][1] : 정수
	
	//배열 초기화
	for (i = 0; i < n && i < 8001; i++) {
		freq[i][0] = 0;
	}

	//정수와 해당 정수의 빈도수를 계산하여 배열에 넣는다.
	int idx = 0;
	int num = 1;

	//이미 정렬된 배열이므로 다른 숫자가 나올 때 까지 해당 정수의 빈도수를 더한다.
	for (i = 0; i < n; i += num) {
		num = 1;
		freq[idx][0]++;		//빈도수 1
		freq[idx][1] = S[i];	//계산할 정수

		//다음 index부터 같은 정수가 존재하는지 검사
		for (j = i + 1; j < n; j++) {
			//같은 정수가 나오면 빈도수 증가
			if (S[i] == S[j]) {
				freq[idx][0]++;
				num++;
			}
			//다른 정수가 나오면 중단.
			else if (S[i] != S[j]) {
				break;
			}
		}
		idx++;
	}

	//최대 빈도수를 계산한다.
	int max = 0;
	for (i = 0; i < idx; i++) {
		if (freq[i][0] > max) {
			max = freq[i][0];
		}
	}

	//빈도수가 최댓값인 정수들을 mode배열에 넣는다.
	num = 0;
	for (i = 0; i < idx; i++) {
		if (freq[i][0] == max) {
			mode[num++] = freq[i][1];
		}
	}

	int result;
	//mode 배열의 원소가 하나인 경우
	if (num == 1) {
		result = mode[0];
	}
	//mode 배열의 원소가 여러개인 경우
	else {
		quick_sort(mode, 0, num - 1);	//정렬 후 2번째로 작은 정수를 결과로
		result = mode[1];
	}
	return result;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, 0, n - 1);	//정렬

	printf("%.0f\n", arithmetic_mean(arr, n));	//산술평균
	int mid = n / 2;
	printf("%d\n", arr[mid]);	//중앙값
	printf("%d\n", get_mode(arr, n));	//최빈값
	int range = arr[n - 1] - arr[0];	
	printf("%d", range);	//범위

	return 0;
}
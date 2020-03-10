/*bj_1427
문제
배열을 정렬하는 것은 쉽다.수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
입력
첫째 줄에 정렬하고자하는 수 N이 주어진다.N은 1, 000, 000, 000보다 작거나 같은 자연수이다.
출력
첫째 줄에 자리수를 내림차순으로 정렬한 수를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int S[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = S[i]; //정렬할 레코드
		//이미 정렬된 부분을 비교하여 key보다 큰 레코드가 나올 때까지 스캔
		for (j = i; j > 0 && S[j - 1] < key; j--) {
			S[j] = S[j - 1];	//하나씩 우측으로 이동
		}
		S[j] = key;	//큰 레코드가 발견되면 해당 자리에 key를 삽입
	}
	for (int k = 0; k < n; k++) {
		printf("%d", S[k]);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int num = n;
	int dec = 0;
	int arr[100];
	int i = 0;
	int dec_num = num;	//10진수

	while (dec_num > 0) {
		arr[i++] = dec_num % 10;
		dec_num /= 10;
	}
	insertion_sort(arr, i);
	return 0;
}
/*bj_2581
문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 
최솟값을 찾는 프로그램을 작성하시오.
예를 들어 M = 60, N = 100인 경우 60이상 100이하의 자연수 중 
소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.
입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.
M과 N은 10, 000이하의 자연수이며, M은 N보다 작거나 같다.
출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다.
단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 - 1을 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>

//소수 판별
bool is_prime(int n) {
	if (n == 1) {	//1인 경우 소수가 아님
		return false;
	}
	for (int i = 2; i < n; i++) {	//1과 자신을 제외하고 나누어 떨어지면 소수가 아님
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int m, n;
	scanf("%d", &m);
	scanf("%d", &n);
	int sum = 0;
	int min = -1;
	for (int i = n; i >= m; i--) {
		if (is_prime(i)) {
			sum += i;
			min = i;
		}
	}
	if (min != -1) {
		printf("%d\n", sum);
	}
	printf("%d", min);
	return 0;
}
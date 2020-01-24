/*
이항계수를 이용하여 nCk 구하기
입력 : nCk에서 n과 k, 출력 : nCk
*/
#include<stdio.h>

//조합 nCk
typedef struct bin_number {
	int n;
	int k;
	int result;
}bin_num;

//bin_num 초기화
void init_bin(bin_num* number, int n, int k) {
	number->n = n;
	number->k = k;
}

int binomical_coefficient(int n, int k) {
	if (k == 0 || n == k) {
		return 1;
	}
	else {
		return binomical_coefficient(n - 1, k - 1) + binomical_coefficient(n - 1, k);     
		//이항정리를 이용하여 재귀호출. 파스칼의 삼각형. 
		//ex)4C2 + 4C3 = 5C3 , 4C2 = 3C1 + 3C2
	}
}
void binomical_action(bin_num* number) {
	number->result = binomical_coefficient(number->n, number->k);
	printf("%dC%d result : %d\n", number->n, number->k, number->result);
}
int main() {
	bin_num num1, num2, num3;
	bin_num* pnum1 = &num1;
	bin_num* pnum2 = &num2;
	bin_num* pnum3 = &num3;
	init_bin(pnum1, 5, 3);
	init_bin(pnum2, 4, 4);
	init_bin(pnum3, 7, 3);

	binomical_action(pnum1);
	binomical_action(pnum2);
	binomical_action(pnum3);

	return 0;
}
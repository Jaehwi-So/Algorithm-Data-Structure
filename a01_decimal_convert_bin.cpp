//#7 양의 정수 n을 입력받아 2진수로 변환된 결과를 출력
#include<stdio.h>

void binary_convert(int num) {
	int bin[64];
	int no=0;
	while (num > 1) {
		bin[no++] = num % 2;
		num = num / 2;
	}
	bin[no] = num;

	for (int i = no; i >= 0; i--) {
		printf("%d", bin[i]);
	}

}
int main() {
	unsigned int num;
	printf("정수 n 입력 : ");
	scanf("%d", &num);
	binary_convert(num);
	return 0;
}
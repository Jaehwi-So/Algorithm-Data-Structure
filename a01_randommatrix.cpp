//문제 : 5*5배열에 중복없이 1부터 50까지의 난수 채워넣기
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main() {

	srand((unsigned)time(NULL));

	int array[5][5];
	int array2[25];
	int i, j;
	int k = 0;

	printf("*****1부터 50까지의 수로 5X5 빙고판 출력*******\n");

	for (i = 0; i < 25; i++) {                                            //배열에 난수 할당
		array2[i] = rand() % 50 + 1;

		for (j = 0; j < i; j++) {                                 //중복 검사
			if (array2[i] == array2[j]) {
				i--;
				break;
			}
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {                               //빙고판 출력
			array[i][j] = array2[k];
			if (array[i][j] < 10) {
				printf(" %d  ", array[i][j]);
			}
			else {
				printf("%d  ", array[i][j]);
			}

			k++;
		}
		printf("\n");
	}
}
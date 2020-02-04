/*
# 행렬의 연산
문제: n by n 크기의 행렬의 곱을 구하시오.
입력 : 양수 n, n by n 크기의 행렬 A와 B
출력 : 행렬 A와 B의 합, 차, 곱 C
*/

#include<stdio.h>
#include<stdlib.h>

int size;	//행렬의 크기

//행렬 생성
int** create_mat(int n) {
	int** mat;
	mat = (int**)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * n);
	}
	return mat;
}

//행렬 덧셈 A+B=C
void m_sum(int n, int(**A), int(**B), int(**C)) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] + B[i][j];
		}
	}
}

//행렬 뺄셈 A-B=C
void m_sub(int n, int(**A), int(**B), int(**C)) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = A[i][j] - B[i][j];
		}
	}
}

//행렬 곱셈 A*B=C
void m_multiply(int n, int(**A), int(**B), int(**C)) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
}


int main() {
	size = 4;
	int a[4][4] = { {1,2,3,4},{2,3,4,5},{10,20,30,40},{11,21,31,41} };
	int b[4][4] = { {1,2,3,4},{2,4,6,8},{3,6,9,12},{4,8,12,16} };
	int** arr1 = create_mat(size);
	printf("=========행렬 A==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr1[i][j] = a[i][j];
			printf("%2d ", arr1[i][j]);
		}
		printf("\n");
	}
	int** arr2 = create_mat(size);
	printf("=========행렬 B==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr2[i][j] = b[i][j];
			printf("%2d ", arr2[i][j]);
		}
		printf("\n");
	}

	int** arr3 = create_mat(size);
	m_sum(size, arr1, arr2, arr3);
	printf("========= A + B ==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%2d ", arr3[i][j]);
		}
		printf("\n");
	}
	m_sub(size, arr1, arr2, arr3);
	printf("========= A - B ==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%2d ", arr3[i][j]);
		}
		printf("\n");
	}
	m_multiply(size, arr1, arr2, arr3);
	printf("========= A * B ==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%2d ", arr3[i][j]);
		}
		printf("\n");
	}


	return 0;
}


/*
쉬트라센의 행렬 곱셈 알고리즘(Strassen Matrix Multiplication)
크기가 큰 행렬의 곱셈을 할 때 행렬을 부분 행렬로 나누어 계산 후 합쳐나가는 분할 정복 알고리즘.

문제: n이 2의 거듭제곱일 때, n by n 크기의 두 행렬의 곱을 구하시오.
입력 : 정수 n, n by n 크기의 행렬 A와 B
출력 : 행렬 A와 B의 곱인 C
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

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

//행렬 합병 C = {C11, C12}{C21, C22}
void merge_matrix(int n, int(**C11), int(**C12), int(**C21), int(**C22), int(**C)) {
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			C[i][j] = C11[i][j];
			C[i][n / 2 + j] = C12[i][j];
			C[n / 2 + i][j] = C21[i][j];
			C[n / 2 + i][n / 2 + j] = C22[i][j];
		}
	}
}

//쉬트라센의 행렬 곱셈 알고리즘
void strassen_multiply(int n, int** A, int** B, int** C) {
	//쉬트라쎈 알고리즘에 필요한 부분 행렬 동적할당
	int threshold = 2;
	int** A11 = create_mat(size);
	int** A12 = create_mat(size);
	int** A21 = create_mat(size);
	int** A22 = create_mat(size);
	int** B11 = create_mat(size);
	int** B12 = create_mat(size);
	int** B21 = create_mat(size);
	int** B22 = create_mat(size);
	int** C11 = create_mat(size);
	int** C12 = create_mat(size);
	int** C21 = create_mat(size);
	int** C22 = create_mat(size);
	int** M1 = create_mat(size);
	int** M2 = create_mat(size);
	int** M3 = create_mat(size);
	int** M4 = create_mat(size);
	int** M5 = create_mat(size);
	int** M6 = create_mat(size);
	int** M7 = create_mat(size);
	int** T1 = create_mat(size);
	int** T2 = create_mat(size);
	
	//행렬의 크기가 임계값(2)일 경우 바로 계산 가능
	if (n == threshold) {
		m_multiply(threshold, A, B, C);
	}

	//행렬의 크기가 임계값보다 클 경우 4개의 부분 행렬로 나눈다.
	else {	
		for (int i = 0; i < n / 2; i++){
			for (int j = 0; j < n / 2; j++) {
				A11[i][j] = A[i][j];
				A12[i][j] = A[i][j + n / 2];
				A21[i][j] = A[i + n / 2][j];
				A22[i][j] = A[i + n / 2][j + n / 2];
				B11[i][j] = B[i][j];
				B12[i][j] = B[i][j + n / 2];
				B21[i][j] = B[i + n / 2][j];
				B22[i][j] = B[i + n / 2][j + n / 2];
			}
		}

		//M1 = (A11+A22)*(B11+B22)
		m_sum(n / 2, A11, A22, T1);
		m_sum(n / 2, B11, B22, T2);
		strassen_multiply(n / 2, T1, T2, M1);
		//M2 = (A21+A22)*(B11)
		m_sum(n / 2, A21, A22, T1);
		strassen_multiply(n / 2, T1, B11, M2);
		//M3 = (A11)*(B12+B22)
		m_sub(n / 2, B12, B22, T2);
		strassen_multiply(n / 2, A11, T2, M3);
		//M4 = (A22)*(B21+B11)
		m_sub(n / 2, B21, B11, T2);
		strassen_multiply(n / 2, A22, T2, M4);
		//M5 = (A11+A12)*(B22)
		m_sum(n / 2, A11, A12, T1);
		strassen_multiply(n / 2, T1, B22, M5);
		//M6 = (A21-A11)*(B11+B12)
		m_sub(n / 2, A21, A11, T1);
		m_sum(n / 2, B11, B12, T2);
		strassen_multiply(n / 2, T1, T2, M6);
		//M7 = (A12-A22)*(B21+B22)
		m_sub(n / 2, A12, A22, T1);
		m_sum(n / 2, B21, B22, T2);
		strassen_multiply(n / 2, T1, T2, M7);

		//C11 = M1+M4-M5+M7
		m_sum(n / 2, M1, M4, T1);
		m_sub(n / 2, T1, M5, T2);
		m_sum(n / 2, T2, M7, C11);
		//C12 = M3+M5
		m_sum(n / 2, M3, M5, C12);
		//C21 = M2+M4
		m_sum(n / 2, M2, M4, C21);
		//C12 = M1+M3-M2+M6
		m_sum(n / 2, M1, M3, T1);
		m_sub(n / 2, T1, M2, T2);
		m_sum(n / 2, T2, M6, C22);
		//C = C11,C12,C21,C22 합병
		merge_matrix(n, C11, C12, C21, C22, C);
	}

	//동적할당 해제
	free(A11);
	free(A12);
	free(A21);
	free(A22);
	free(B11);
	free(B12);
	free(B21);
	free(B22);
	free(C11);
	free(C12);
	free(C21);
	free(C22);
	free(M1);
	free(M2);
	free(M3);
	free(M4);
	free(M5);
	free(M6);
	free(M7);
	free(T1);
	free(T2);
}

int main() {
	/*              4*4 행렬 계산           */
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
	strassen_multiply(size, arr1, arr2, arr3);
	printf("========= A * B ==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%4d ", arr3[i][j]);
		}
		printf("\n");
	}

	/*              16*16 행렬 계산           */
	size = 16;
	int c[16][16];
	int d[16][16];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			c[i][j] = i + j;
			d[i][j] = (32 + i - j);
		}
	}
	int** arr4 = create_mat(size);
	printf("=========행렬 C==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr4[i][j] = c[i][j];
			printf("%3d ", arr4[i][j]);
		}
		printf("\n");
	}
	int** arr5 = create_mat(size);
	printf("=========행렬 D==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr5[i][j] = d[i][j];
			printf("%3d ", arr5[i][j]);
		}
		printf("\n");
	}

	int** arr6 = create_mat(size);
	strassen_multiply(size, arr4, arr5, arr6);
	printf("========= C * D ==========\n");
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%5d ", arr6[i][j]);
		}
		printf("\n");
	}
	free(arr1);
	free(arr2);
	free(arr3);
	free(arr4);
	free(arr5);
	free(arr6);
	return 0;
}





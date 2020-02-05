/*
# 연쇄 행렬 곱셈의 최소곱셈 알고리즘 (Minimum Multiplication)
다수의 행렬의 곱셈을 수행할 때 연산을 최소로 하게 되는 최적 순서 P[] 구축, 최소값 구하기
*/
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int M[MAX_SIZE][MAX_SIZE];  //M[i][j] = i~j까지 행렬 곱셈을 하는 데 필요한 최소 연산 횟수
int P[MAX_SIZE][MAX_SIZE]; //P[i][j] = i~j까지 행렬 곱셈을 하는 데 최적 순서로 갈라지는 index지점
int d[MAX_SIZE];    //d : 행렬의 열의 개수

//연쇄 행렬 곱셈 문제의 최적 순서 구축
void chain_multiplication(int column[], int n) {
    for (int i = 0; i <= n; i++) {
        d[i] = column[i];
    }

    for (int diag = 0; diag < n; diag++) {
        for (int i = 1; i <= n - diag; i++) {
            int j = i + diag;
            if (j == i) {   //대각선의 경우 연산횟수 0
                M[i][j] = 0;
                continue;
            }
            M[i][j] = INT_MAX;  
            for (int k = i; k <= j - 1; k++) {  //나머지 대각선에 대해서 최소 연산 횟수와 그 때의 k값(최적 순서로 갈라지는 지점) 찾음
                if (M[i][j] > M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j]) {
                    M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                    P[i][j] = k;
                }
            }
        }
    }
}

//결과 출력
void print_result(int n) {
    printf("=====M[i][j]=====\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("=====P[i][j]=====\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%3d ", P[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Min multiplication : %d", M[1][n]);
}
int main() {
    int size = 4;
    int column[5] = { 5,3,4,3,10 };
    //4개의 행렬 5x3 3x4 4x3 3x10 
    chain_multiplication(column, size);
    print_result(size);
    return 0;
}


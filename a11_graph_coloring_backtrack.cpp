/*
# 그래프 색칠하기 문제
그래프들의 모든 노드를 색칠하는 문제. 단 인접한 노드는 서로 다른 색으로 칠해져야 한다.
*/
#include<stdio.h>
#include<stdlib.h>

int n = 4;  //그래프의 노드 수
int n_color = 3;  //칠할 수 있는 색의 종류
int adj_mat[4][4] = { {0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0} };    //그래프(인접 행렬)
int color[4];  //그래프에 색을 칠하는 방법

//유망성 판단
bool promising(int i){
    int j =0 ;
    for (int j = 0; j < i; j++) {
        if (adj_mat[i][j] == 1 && color[i] == color[j]) { //인접한 노드가 색이 같으면 유망하지 않다.
            return false;
        }
    }
    return true;
}

//인접 행렬 출력
void print_adj_mat() {
    printf("=======인접 행렬=======\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj_mat[i][j]);
        }
        printf("\n");
    }
    printf("======================\n");
}

//경우의 수 출력
void print_result() {
    for (int i = 1; i <= n; i++) {
        if (i == n) printf("%d", color[i]);
        else printf("%d -> ", color[i]);
    }
    printf("\n");
}

//그래프 색칠 알고리즘
void graph_coloring(int i){ //i : 현재 색칠된 노드의 수

    if (promising(i)) { //만약 현재 마디가 유망하다면
        if (i == n) {   //모든 노드가 색칠된 경우 = 해
            print_result();
        }
        else {
            for (int k = 1; k <= n_color; k++) { 
                color[i + 1] = k;  //다음 노드에 모든색을 시도해본다.
                graph_coloring(i + 1);  //가지치기
            }
        }
    }
}

int main(){
    print_adj_mat();
    graph_coloring(0);
    return 0;
}

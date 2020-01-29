/*
# 해밀토니안 회로 문제(Hamiltonian circuits)
그래프의 정점들을 한 번씩만 거쳐서 모든 정점을 순회하고 다시 시작정점으로 돌아오는 경우의 수 구하기
*/
#include<stdio.h>
#include<stdlib.h>

int n = 5;  //그래프의 노드 수
int adj_mat[5][5] = { {0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0} };    //그래프(인접 행렬)
int path[5] = {-1,-1,-1,-1,-1};  //정점을 지나는 방법

//경우의 수 출력
void print_result() {
    for (int i = 0; i < n; i++) {
        if (i == n-1) printf("%d", path[i]);
        else printf("%d -> ", path[i]);
    }
    printf("\n");
}
//유망성 판단
bool promising(int i){
    if (i == n - 1 && !adj_mat[path[n - 1]][path[0]]) { //마지막 정점은 처음 정점과 인점해야 한다.
        return false;
    }
    if (i > 0 && !adj_mat[path[i - 1]][path[i]]) {  //정점은 경로상에서 전의 정점과 인접해야 한다.
        return false;
    }
    for (int j = 0; j < i; j++) {   //정점은 지나온 정점이 될 수 없다.
        if (path[i] == path[j]) {
            return false;
        }
    }   
    return true;    //세가지 조건을 모두 만족하면 유망하다고 판단
}



//해밀토니안 회로 알고리즘
void hamiltonian_cir(int i, int start) { //i : 현재 지나온 노드의 수, start : 시작 정점 index
   
    if(i == 0) path[0] = start;    //경로에서 시작 정점 설정 

    if (promising(i)) { //만약 현재 마디가 유망하다면
        if (i == n - 1) {   //모든 노드를 지나온 경우 = 해
            print_result();
        }
        else {
                for (int k = 0; k < n; k++) {
                    path[i + 1] = k;  //다음 경로로 모든 노드의 경우의 수를 시도한다.
                    hamiltonian_cir(i + 1, start);  //가지치기
                }
            }
        }
    }


int main() {
    hamiltonian_cir(0,0);
    return 0;
}

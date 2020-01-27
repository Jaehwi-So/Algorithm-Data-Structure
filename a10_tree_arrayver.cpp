//배열로 트리 구축
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE   100

//배열로 구성된 트리. 
//root index *2 = left  && root index *2 + 1 = right 
typedef struct tree {
	int data[MAX_SIZE];
}Tree;

//트리 초기화
void init_tree(Tree* t) {
	for (int i = 0; i < MAX_SIZE; i++) {
		t->data[i] = -1;
	}
}

//노드 정보 출력
void print_tree(Tree* t, int node) {
	printf("[node : %d]=", t->data[node]);
	if (t->data[node *2] != -1) {	//자식 left 노드 idx = 부모 노드 *2
		printf("[left : %d]", t->data[node *2]);
	}
	if (t->data[(node * 2)+1] != -1) {	//자식 left 노드 idx = 부모 노드 *2 +1
		printf("[right : %d]", t->data[(node *2)+1]);
	}
	printf("\n");
}

int main(void)
{
	Tree* t1 = (Tree*)malloc(sizeof(Tree));
	int tree_mat[16] = {-1,11,12,13,14,15,16,17,18,19,100,110,-1,-1,-1,150 };
	init_tree(t1);

	for (int i = 1; i < 16; i++) {
		t1->data[i] = tree_mat[i];
	}

	print_tree(t1, 1);
	print_tree(t1, 2);
	print_tree(t1, 3);
	print_tree(t1, 4);
	print_tree(t1, 7);


	return 0;
}


//배열로 트리 구축, 전위 순회/중위 순회/후위 순회 구현
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE   100

//배열로 구성된 트리. 
//root index *2 = left  && root index *2 + 1 = right 
typedef struct tree {
	int data[MAX_SIZE];	
}Tree;

//트리 초기화
void init_tree(Tree* t){
	for (int i = 0; i < MAX_SIZE; i++){
		t->data[i] = -1;
	}
}

//전위 순회
void preorder_tree(Tree* t, int root){
	if ((t->data[root] != -1) && (root < MAX_SIZE)){
		printf("[%d]", t->data[root]); // 노드 방문
		preorder_tree(t, root * 2); // 왼쪽 서브트리 
		preorder_tree(t, root * 2 + 1);// 오른쪽 서브트리 
	}
}

//중위 순회
void inorder_tree(Tree* t, int root){
	if((t->data[root] != -1) && (root < MAX_SIZE)){
		inorder_tree(t, root * 2);// 왼쪽 서브트리 
		printf("[%d]", t->data[root]);// 노드 방문
		inorder_tree(t, root * 2 + 1);// 오른쪽 서브트리 
	}
}

//후위 순회
void postorder_tree(Tree* t, int root) {
	if ((t->data[root] != -1) && (root < MAX_SIZE)){
		postorder_tree(t, root * 2);// 왼쪽 서브트리 
		postorder_tree(t, root * 2 + 1);// 오른쪽 서브트리 
		printf("[%d]", t->data[root]);// 노드 방문
	}
}

int main(void)
{
	Tree* t1 = (Tree*)malloc(sizeof(Tree));
	int tree_mat[16] = { -1,1,2,3,4,5,6,7,8,9,10,11,-1,-1,-1,15 };
	init_tree(t1);

	for (int i = 1; i < 16; i++) {
		t1->data[i] = tree_mat[i];
	}

	printf("전위 순회 VLR : ");
	preorder_tree(t1, 1);
	printf("\n");
	printf("중위 순회 LVR : ");
	inorder_tree(t1, 1);
	printf("\n");
	printf("후위 순회 LRV : ");
	postorder_tree(t1, 1);
	printf("\n");
	return 0;
}


//포인터 링크를 이용하여 트리 구축
#include <stdio.h>
#include <stdlib.h>

//노드의 링크로 구성된 트리. 
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;	//자식 노드 left, right
} TreeNode;

//노드 정보 출력
void print_tree(TreeNode* root) {
	printf("[node : %d]=", root->data);
	if (root->left != NULL) {
		printf("[left : %d]", root->left->data);
	}
	if (root->right != NULL) {
		printf("[right : %d]", root->right->data);
	}
	printf("\n");
}

int main(void)
{
	TreeNode *n1, *n2, *n3, *n4;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));
	n4 = (TreeNode*)malloc(sizeof(TreeNode));
	n1->data = 1;		
	n1->left = n2;
	n1->right = n3;
	n2->data = 2;		
	n2->left = n4;
	n2->right = NULL;
	n3->data = 3;		
	n3->left = NULL;
	n3->right = NULL;
	n4->data = 4;		
	n4->left = NULL;
	n4->right = NULL;
	print_tree(n1);
	print_tree(n2);
	print_tree(n3);
	print_tree(n4);
	free(n1); 
	free(n2);
	free(n3);
	free(n4);
	return 0;
}
//포인터 링크를 이용하여 트리 구축, 전위 순회/중위 순회/후위 순회 구현
#include <stdio.h>
#include <stdlib.h>

//노드의 링크로 구성된 트리. 
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right; //자식 노드 left, right
} TreeNode;

// 전위 순회
void preorder_tree(TreeNode* root) {
	if (root != NULL) {
		printf("[%d]", root->data);  // 노드 방문
		preorder_tree(root->left);// 왼쪽 서브트리 
		preorder_tree(root->right);// 오른쪽 서브트리 
	}
}
// 중위 순회
void inorder_tree(TreeNode* root) {
	if (root != NULL) {
		inorder_tree(root->left);// 왼쪽 서브트리
		printf("[%d]", root->data);  // 노드 방문
		inorder_tree(root->right);// 오른쪽 서브트리
	}
}

// 후위 순회
void postorder_tree(TreeNode* root) {
	if (root != NULL) {
		postorder_tree(root->left);// 왼쪽 서브트리 
		postorder_tree(root->right);// 오른쪽 서브트리
		printf("[%d]", root->data);  // 노드 방문
	}
}
int main(void)
{
	TreeNode n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
	n1 = { 1, &n2, &n3 };
	n2 = { 2, &n4, &n5 };
	n3 = { 3, &n6, &n7 };
	n4 = { 4, &n8, &n9 };
	n5 = { 5, NULL, &n10 };
	n6 = { 6, NULL, NULL };
	n7 = { 7, NULL, NULL };
	n8 = { 8, NULL, NULL };
	n9 = { 9, NULL, NULL };
	n10 = { 10, NULL, NULL };
	TreeNode* root = &n1;

	printf("전위 순회 VLR : ");
	preorder_tree(root);
	printf("\n");
	printf("중위 순회 LVR : ");
	inorder_tree(root);
	printf("\n");
	printf("후위 순회 LRV : ");
	postorder_tree(root);
	printf("\n");
	return 0;
}
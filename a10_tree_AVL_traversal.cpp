//AVL 트리 순회
#include<stdio.h> 
#include<stdlib.h> 
#include "a10_tree_AVL.h"

// 전위 순회
void preorder_tree(Node* root) {
	if (root != NULL) {
		printf("[%d]", root->key);  // 노드 방문
		preorder_tree(root->left);// 왼쪽 서브트리 
		preorder_tree(root->right);// 오른쪽 서브트리 
	}
}
// 중위 순회
void inorder_tree(Node* root) {
	if (root != NULL) {
		inorder_tree(root->left);// 왼쪽 서브트리
		printf("[%d]", root->key);  // 노드 방문
		inorder_tree(root->right);// 오른쪽 서브트리
	}
}

// 후위 순회
void postorder_tree(Node* root) {
	if (root != NULL) {
		postorder_tree(root->left);// 왼쪽 서브트리 
		postorder_tree(root->right);// 오른쪽 서브트리
		printf("[%d]", root->key);  // 노드 방문
	}
}

Node* insert(Node* root, int key, int traversal_type) {
	root = insert_node(root, key);
	if (traversal_type == 1) {
		printf("preorder ");
		preorder_tree(root);
	}
	else if (traversal_type == 2) {
		printf("postorder ");
		postorder_tree(root);
	}
	else {
		printf("inorder ");
		inorder_tree(root);
	}
	printf("\n");
	return root;
}
int main(void)
{
	Node* root = NULL;

	// 예제 트리 구축
	root = insert(root, 7, 1);
	root = insert(root, 8, 1);
	root = insert(root, 9, 1);
	root = insert(root, 2, 1);
	root = insert(root, 1, 1);

	free(root);

	Node* root2 = NULL;
	root2 = insert(root2, 1, 3);
	root2 = insert(root2, 4, 3);
	root2 = insert(root2, 2, 3);
	root2 = insert(root2, 5, 3);
	root2 = insert(root2, 6, 3);
	root2 = insert(root2, 3, 3);

	Node* root3 = NULL;
	root3 = insert(root3, 7, 2);
	root3 = insert(root3, 5, 2);
	root3 = insert(root3, 3, 2);
	root3 = insert(root3, 9, 2);
	root3 = insert(root3, 1, 2);

	return 0;
}
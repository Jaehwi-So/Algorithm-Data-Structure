#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;	//key값
	struct TreeNode* left, * right;	//자식 노드 left, right
} TreeNode;

//노드 생성
TreeNode* create_node(int key) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//노드 삽입, 새로운 루트노드 반환
TreeNode* insert_node(TreeNode* node, int key)
{
	if (node == NULL) {	// 공백인 곳에 새로운 노드를 생성한다.
		TreeNode* n = create_node(key);
		return n;
	}
	if (key < node->key) {	//key값이 현재 노드보다 작으면 왼쪽 서브트리로 이동
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) {	//key값이 현재 노드보다 크면 오른쪽 서브트리로 이동
		node->right = insert_node(node->right, key);
	}
	return node;	//변경된 루트 반환
}

//노드 삭제, 새로운 루트노드 반환
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	if (key < root->key) {
		root->left = delete_node(root->left, key);	// key값이 현재 노드의 key값보다 작으면 왼쪽 서브트리에 key 존재
	}

	else if (key > root->key) {
		root->right = delete_node(root->right, key);// key값이 현재 노드의 key값보다 크면 오른쪽 서브트리에 key 존재
	}

	else if (key == root->key) { // key값이 현재 노드의 key값과 같으면 삭제
		if (root->left == NULL && root->right == NULL) {	//왼쪽, 오른쪽 서브트리가 존재하지 않는 경우
			free(root);
			return NULL;
		}
		else if (root->left == NULL) {	//오른쪽 서브트리가 존재하는 경우
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {	//왼쪽 서브트리가 존재하는 경우
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		else {	//양쪽 서브트리가 존재하는 경우
			TreeNode* successor = root->right; //후계 노드, 오른쪽 서브트리에서 가장 작은 key값의 노드
			while (successor->left != NULL) {
				successor = successor->left;
			}
			root->key = successor->key;		// 후계 노드로 삭제할 노드 대체
			root->right = delete_node(root->right, successor->key);// 후계 노드 위치 삭제
		}
	}
	return root;
}

//중위 순회
void inorder_tree(TreeNode* root) {
	if (root != NULL) {
		inorder_tree(root->left);// 왼쪽 서브트리
		printf("[%d]", root->key);  // 노드 방문
		inorder_tree(root->right);// 오른쪽 서브트리
	}
}

//이진 트리 탐색 
TreeNode* search_tree(TreeNode* node, int key) {
	if (node == NULL) {
		return NULL;	//탐색 실패
	}
	if (key == node->key) {	//key값과 일치
		return node;
	}
	else if (key < node->key) {	//key값이 현재 노드의 key값보다 작으면 왼쪽 서브트리 탐색
		return search_tree(node->left, key);
	}
	else {	//key값이 현재 노드의 key값보다 크면 오른쪽 서브트리 탐색
		return search_tree(node->right, key);
	}
}

void found(TreeNode* root, int key) {
	if (search_tree(root, key) != NULL) {
		printf("%d 탐색 성공\n", key);
	}
	else {
		printf("%d 탐색 실패\n", key);
	}
}

int main(void)
{
	TreeNode* root = NULL;

	int key_arr[10] = { 30,60,50,10,20,70,90,40,80,100 };
	for (int i = 0; i < 10; i++) {
		root = insert_node(root, key_arr[i]);
	}
	printf("중위 순회 : ");
	inorder_tree(root);
	printf("\n");
	root = delete_node(root, 60);
	root = delete_node(root, 40);
	root = delete_node(root, 100);
	printf("40, 60, 100 삭제 \n");
	printf("중위 순회 : ");
	inorder_tree(root);
	printf("\n");
	found(root, 20);
	found(root, 50);
	found(root, 60);
	found(root, 70);
	found(root, 100);
	printf("\n");

}
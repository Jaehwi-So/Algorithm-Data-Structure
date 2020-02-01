//AVL 트리 구축
#include<stdio.h> 
#include<stdlib.h> 
#include"a10_tree_AVL.h"

int get_max(int a, int b) {
	if (a > b) {
		return a;
	}
	else return b;
}

// 트리의 높이를 반환
int get_height(Node* node) {
	int height = 0;
	if (node != NULL) {
		height = get_max(get_height(node->left), get_height(node->right)) + 1;
	}
	return height;
}
// 노드의 균형인수를 반환
int get_balance(Node* node) {
	if (node == NULL) {
		return 0;
	}
	else {
		return get_height(node->left) - get_height(node->right);
	}
}

//노드 생성
Node* create_node(int key) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//오른쪽 회전(LL-Rotate)
Node* LL_rotate(Node* parent) {
	Node* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;	//왼쪽 자식이 루트노드가 된다.
}

//왼쪽 회전(RR-Rotate)
Node* RR_rotate(Node* parent) {
	Node* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;	//오른쪽 자식이 루트노드가 된다.
}

//하위 구간을 왼쪽 회전 후 오른쪽 회전(LR-Rotate)
Node* LR_rotate(Node* parent) {
	Node* child = parent->left;
	parent->left = RR_rotate(child);	//RR회전 후
	return LL_rotate(parent);	//LL회전
}

//하위 구간을 오른쪽 회전 후 왼쪽 회전(LR-Rotate)
Node* RL_rotate(Node* parent) {
	Node* child = parent->right;
	parent->right = LL_rotate(child);	//LL회전후
	return RR_rotate(parent);	//RR회전
}

//노드 추가
Node* insert_node(Node* node, int key) {
	if (node == NULL) {	//노드 추가
		Node* n = create_node(key);
		return n;
	}

	if (key < node->key) {	//현재 노드보다 키값이 작으면 왼쪽에 삽입
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) {	//현재 노드보다 키값이 크면 오른쪽에 삽입
		node->right = insert_node(node->right, key);
	}
	else {	//현재 노드와 키값이 동일하면 삽입하지 않는다.
		return node;
	}

	int bal_fac = get_balance(node);	//균형인수

	//균형이 깨지는 경우(높이차이 2이상) 회전으로 균형을 맞춤
	if (bal_fac > 1) {	
		if (key < node->left->key) {	//LL 타입
			return LL_rotate(node);	
		}
		if (key > node->left->key) {	//LR 타입
			return LR_rotate(node);	
		}
	}
	else if (bal_fac < -1){
		if (key > node->right->key) {	//RR 타입
			return RR_rotate(node);
		}
		if (key < node->right->key) {	//RL 타입
			return RL_rotate(node);	
		}
	}
	return node;
}


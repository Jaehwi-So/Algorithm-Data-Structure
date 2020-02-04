/*
# 허프만 트리 구축/ 허프만 코드 생성
문서를 위한 허프만 코드는 문서에 나타나는 서로 다른 문자에 대해 각각 하나의 리프를 갖는 우선순위 큐로부터 생성됨
각각의 문자에 대한 코드는 그 문자에 대한 루트-리프 경로에 의해 결정되는데
왼쪽 가지는 “0”으로 표시되고, 오른쪽 가지는 “1”로 표시됨
오른쪽-왼쪽-오른쪽으로 가는 루트-리프 경로는 코드 101로 정해짐
*/
#include <stdio.h>
#include <stdlib.h>
#include "a10_huffman_tree_heap.h"

/*
//트리 노드
typedef struct TreeNode {
	int weight;	//빈도수
	char ch;	//문자
	struct TreeNode* left;	//왼쪽 자식
	struct TreeNode* right;	//오른쪽 자식
} TreeNode;

//히프에 삽입될 단말노드
typedef struct {
	TreeNode* root;	//트리를 가리키는 포인터
	char ch;	//문자
	int key;	//빈도수
} element;
*/

// 이진 트리 생성 
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}

//허프만 코드 생성
void huffman_codes(TreeNode* root, int huf_codes[], int top) {
	//왼쪽 자식 -> 코드에 1 저장
	if (root->left != NULL) {
		huf_codes[top] = 1;
		huffman_codes(root->left, huf_codes, top + 1);
	}

	//오른쪽 자식 -> 코드에 0 저장
	if (root->right != NULL) {
		huf_codes[top] = 0;
		huffman_codes(root->right, huf_codes, top + 1);
	}

	//단말노드이면 최종 코드 
	if (root->left == NULL && root->right == NULL) {
		printf("%c: ", root->ch);
		for (int i = 0; i < top; i++) {
			printf("%d", huf_codes[i]);
		}
		printf("\n");

	}

}

//허프만 트리 구축
void huffman_tree(int frequency_arr[], char char_arr[], int n)
{
	TreeNode* node;
	Heap* heap;
	element new_node, min_left, min_right;

	heap = create_heap();
	init_heap(heap);
	for (int i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		new_node.ch = node->ch = char_arr[i];
		new_node.key = node->weight = frequency_arr[i];
		new_node.root = node;
		insert_heap(heap, new_node);	//문자와 빈도(key값)을 가진 단말노드들을 heap에 넣는다.
	}
	for (int i = 0; i < n - 1; i++) {
		min_left = delete_heap(heap);
		min_right = delete_heap(heap);
		node = make_tree(min_left.root, min_right.root);	// 최소 빈도값을 가지는 두개의 노드를 합쳐 트리를 구축한다.
		node->weight = min_left.key + min_right.key;
		new_node.key = node->weight;
		new_node.root = node;
		printf("(%d + %d) = %d \n", min_left.key, min_right.key, new_node.key);
		insert_heap(heap, new_node);	//두 개의 노드를 합친 단말노드를 heap에 넣는다.
	}
	new_node = delete_heap(heap); //마지막으로 남은 노드 = 모든 빈도수를 합친 노드 = 허프만 트리의 루트 노드

	int huf_codes[50];
	int top = 0;
	huffman_codes(new_node.root, huf_codes, top);	//허프만 코드 구함
	free(heap);
}

int main(void)
{
	int frequency_arr[] = { 4, 6, 8, 12, 15 };	//빈도수 비열
	char char_arr[] = { 'a', 'e', 'i', 'o', 'u' };	//문자 배열
	huffman_tree(frequency_arr, char_arr, 5);
	return 0;
}
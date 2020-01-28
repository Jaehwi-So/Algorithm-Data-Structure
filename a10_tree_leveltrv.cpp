//포인터 링크를 이용하여 트리 구축, 레벨 순회 구현
#include <stdio.h>
#include <stdlib.h>
#include "a10_tree_leveltrv_queue.h"
//노드의 링크로 구성된 트리. 


//레벨 순회
void level_order(TreeNode* root)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	init_queue(q);	 

	if (root == NULL) return;
	enqueue(q, root);	//큐에 현재노드 enqueue. 백트래킹 지점
	while (!is_empty(q)) {
		root = dequeue(q);	//백트래킹
		printf(" [%d] ", root->data);
		if (root->left)	//left존재시 enqueue
			enqueue(q, root->left);
		if (root->right)	//right존재시 enqueue
			enqueue(q, root->right);
	}
	free(q);
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

	printf("레벨 순회 : ");
	level_order(root);
	printf("\n");

}

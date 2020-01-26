/*
#이중 연결리스트 구현
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node* l_link;
	struct Node* r_link;
}Node;

void init_list(Node* head) {
	head->l_link = head;
	head->r_link = head;
}
//새로운 노드를 노드(lst) 오른쪽에 삽입.
Node* insert_node(Node* lst, int value) {
	Node* n = (Node*)malloc(sizeof(Node));   //노드 생성
	n->data = value;
	n->l_link = lst;
	n->r_link = lst->r_link;
	lst->r_link->l_link = n;
	lst->r_link = n;
	return lst;
}
//노드 removed 삭제
Node* delete_node(Node* head, Node* removed) {
	if (removed == head)return head;
	removed->l_link->r_link = removed->r_link;
	removed->r_link->l_link = removed->l_link;
	free(removed);
	return head;
}

void print_list(Node* head) {
	Node* n;
	for (n = head->r_link; n != head; n = n->r_link) {
		printf("<-%d->", n->data);
	}
	printf("\n");
}

int main() {
	Node* n = (Node*)malloc(sizeof(Node));
	init_list(n);
	for (int i = 0; i < 5; i++) {
		n = insert_node(n, i);
		print_list(n);
	}
	for (int i = 0; i < 5; i++) {
		n = delete_node(n, n->r_link);
		print_list(n);
	}
	return 0;

}

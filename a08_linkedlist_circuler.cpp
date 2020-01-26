/*
#원형 리스트를 이용하여 플레이어 3명이 차례로 게임을 진행하는 과정 print하기
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

//첫번째 헤드로 노드 삽입.
Node* insert_node(Node* head, int value) {
	Node* n = (Node*)malloc(sizeof(Node));   //노드 생성
	n->data = value;
	if (head == NULL) {
		head = n;
		n->link = head;
	}
	else {
		n->link = head->link;
		head->link = n;
	}
	return head;		//head node 반환
}

void game_start(Node* head) {
	Node* n = head;
	for (int i = 0; i < 10; i++) {
		printf("현재 차례 : player %d\n", n->data);
		n = n->link;
	}
}

int main() {
	Node* n = NULL;
	n = insert_node(n, 1);
	n = insert_node(n, 2);
	n = insert_node(n, 3);
	game_start(n);
	return 0;
}

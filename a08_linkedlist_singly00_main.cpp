/*
#단순 연결 리스트 구현
*/
#include<stdio.h>
#include<stdlib.h>
#include "a08_linkedlist_singly01.h"
int main() {
	Node* n = NULL;

	for (int i = 1; i <= 10; i++) {
		printf("헤드에 노드 %d 삽입 : ",i);
		n = first_insert_node(n, i);
		print_node(n);
	}

	for (int i = 1; i <= 2; i++) {
		printf("헤드 노드 삭제 : ");
		n = first_delete_node(n);
		print_node(n);
	}

	for (int i = 1; i < 10; i+=2) {
		printf("index %d 다음 노드 삭제 : ",i);
		n = delete_node(n, i);
		print_node(n);
		i += 2;
		printf("index %d 다음에 노드 %d 추가 : ", i, i+2);
		n = insert_node(n, i, i+2);
		print_node(n);
	}
	return 0;
}
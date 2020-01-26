#include<stdio.h>
#include<stdlib.h>
#include "a08_linkedlist_singly01.h"

//첫번째 헤드로 노드 삽입.
Node* first_insert_node(Node* head, int value) {
	Node* n = (Node*)malloc(sizeof(Node));   //노드 생성
	n->data = value;		//노드의 data에 value를 넣고 link에 현재의 head를 연결한다.
	n->link = head;
	head = n;				//head를 연결된 노드로 설정한다.
	return head;		//head node 반환
}

//해당 노드 뒤에 노드 삽입
Node* idx_insert_node(Node* head, Node* node, int value) {
	Node* n = (Node*)malloc(sizeof(Node));	//노드 생성
	n->data = value;		//노드의 data에 valuse를 넣고 삽입된 노드의 link에 삽입될 위치의 다음 노드를 연결한다.		
	n->link = node->link;
	node->link = n;		//삽입된 노드 이전 노드의 link를 삽입된 노드와 연결한다.
	return head;		//head node 반환
}

//첫번째 노드 삭제
Node* first_delete_node(Node* head) {
	Node* nod;	//헤드의 정보를 담아둘 node 생성
	if (head == NULL) {
		return NULL;
	}	//리스트가 공백이라면 공백 return	
	nod = head;
	head = nod->link;	//head를 다음 연결node의 link node로 설정
	free(nod);			//만들어둔 node 할당 해제
	return head;		//head node 반환
}

//해당 노드 뒤의 노드 삭제
Node* idx_delete_node(Node* head, Node* node) {
	Node* removed;	//사라질 노드의 정보를 담을 removed생성
	removed = node->link;
	node->link = removed->link;	//node의 link를 사라질 노드의 link로 설정. 
	free(removed);			//만들어둔 node 할당 해제
	return head;		//head node 반환
}

void print_node(Node* head) {
	for (Node* n = head; n != NULL; n = n->link) {
		printf("%d->",n->data);
	}
	printf("NULL\n");
}

//index번째 노드 다음 노드를 삭제하는 함수. 리스트에 해당 index가 없으면 삭제하지 않는다.
Node* delete_node(Node* node, int index) {
	int seq=0;
	if (index == 0) {
		return first_delete_node(node);
	}
	for (Node* n = node; n != NULL; n = n->link) {
		if (seq == index) {
			return idx_delete_node(node, n);
		}
		seq++;
	}
	return node;
}

//index번째 노드 다음에 노드를 추가하는 함수. 리스트에 해당 index가 없다면 꼬리에 노드 추가
Node* insert_node(Node* node, int index, int value) {
	int seq = 0;
	Node* n;
	if (index == 0) {
		return first_insert_node(node, value);
	}
	for (n = node; n != NULL; n = n->link) {
		if (seq == index) {
			return idx_insert_node(node, n, value);
		}
		if (n->link == NULL) {
			return idx_insert_node(node, n, value);
		}
		seq++;
	}
}

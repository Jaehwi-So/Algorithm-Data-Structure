#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

//typedef int element;

typedef struct Node{
	int data;
	struct Node *link;
}Node;

//첫번째 헤드로 노드 삽입.
Node* first_insert_node(Node *head, int value){
	Node *n=(Node*)malloc(sizeof(Node));   //노드 생성
	n->data=value;		//노드의 data에 value를 넣고 link에 현재의 head를 연결한다.
	n->link=head;
	head=n;				//head를 연결된 노드로 설정한다.
	return head;		//head node 반환
}

//노드 뒤에 노드 삽입
Node* insert_node(Node *head, Node *node, int value){
	Node *n=(Node*)malloc(sizeof(Node));	//노드 생성
	n->data=value;		//노드의 data에 valuse를 넣고 삽입된 노드의 link에 삽입될 위치의 다음 노드를 연결한다.		
	n->link=node->link;	
	node->link=n;		//삽입된 노드 이전 노드의 link를 삽입된 노드와 연결한다.
	return head;		//head node 반환
}

//첫번째 노드 삭제
Node* first_delete_node(Node *head){
	Node *nod=(Node*)malloc(sizeof(Node));	//헤드의 정보를 담아둘 node 생성
	if(head==NULL){
		return NULL;}	//리스트가 공백이라면 공백 return	
	nod=head;	
	head=nod->link;	//head를 다음 연결node의 link node로 설정
	free(nod);			//만들어둔 node 할당 해제
	return head;		//head node 반환
}

//노드 뒤에 노드 삭제
Node* delete_node(Node *head, Node *node){
	if(head==NULL){ 
		return NULL;}	//리스트가 공백이라면 공백 return
	Node *removed=(Node*)malloc(sizeof(Node));	//사라질 노드의 정보를 담을 removed생성
	removed=node->link;
	node->link=removed->link;	//node의 link를 사라질 노드의 link로 설정. 
	free(removed);			//만들어둔 node 할당 해제
	return head;		//head node 반환
}

void print_node(Node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head=head->link;
	}
}

//
int main(){
	Node *n=NULL;
	n=first_insert_node(n, 3);
	n=first_insert_node(n, 2);
	n=first_insert_node(n, 1);
	n=first_insert_node(n, 0);
	n=first_delete_node(n);
	print_node(n);
	system("pause");
	return 0;

}
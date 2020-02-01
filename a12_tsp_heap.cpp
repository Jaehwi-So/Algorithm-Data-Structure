#include "a12_tsp_heap.h"
/*
typedef struct Node {
	int bound;	//현재 마디의 bound값
	int i;	//현재 마디의 수준
	int pt[10];	//현재 마디의 경로
};
*/

//노드 생성
Node create_node() {
	Node n1;
	n1.bound = 0;
	n1.i = 0;
	return n1;
}

//히프 생성
Heap* create_heap() {
	return (Heap*)malloc(sizeof(Heap));
}

//히프 초기화
void init_heap(Heap* h) {
	h->heap_size = 0;
}

//히프 삽입
void insert_heap(Heap* h, element item) {
	int i;
	i = ++(h->heap_size);	//히프 사이즈 증가

	//루트에 도달하지 않았고 삽입하려는 노드가 부모 노드보다 작다면
	while ((i != 1) && (item.bound < h->data[i / 2].bound)) {
		h->data[i] = h->data[i / 2];	//부모 노드는 자식 노드로 이동
		i /= 2;	//부모 노드로 검사범위 이동
	}
	h->data[i] = item;	//삽입 위치를 찾았으면 노드 삽입
}

//삭제 함수
element delete_heap(Heap* h) {
	int parent, child;
	element item, temp;
	item = h->data[1]; //루트 노드
	temp = h->data[(h->heap_size)--]; //빈 루트 노드 자리에 들어갈 히프의 마지막 노드
	parent = 1;
	child = 2;

	//히프 전체를 순회한다.
	while (child <= h->heap_size) {

		//자식노드 중 더 작은 자식노드를 찾는다.
		if ((child <= h->heap_size) && (h->data[child].bound) > h->data[child + 1].bound) {
			child++;
		}

		//만약 자식노드보다 현재 노드가 작다면 순회를 멈춘다.
		if (temp.bound < h->data[child].bound) {
			break;
		}

		//검사 노드를 한 단계 아래로 이동
		h->data[parent] = h->data[child];
		parent = child;
		child *= 2;
	}
	h->data[parent] = temp;
	return item;
}


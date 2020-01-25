//# 히프 구현

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100
//히프
typedef struct {
	int element[MAX_SIZE]; //레코드
	int heap_size;	//힙 크기
}Heap;

//히프 생성
Heap* create_heap() {
	return (Heap*)malloc(sizeof(Heap));
}

//히프 초기화
void init_heap(Heap* h) {
	h->heap_size = 0;
}

//히프 삽입
void insert_heap(Heap* h, int item) {
	int i;
	i = ++(h->heap_size);	//히프 사이즈 증가

	//루트에 도달하지 않았고 삽입하려는 노드가 부모 노드보다 크다면
	while ((i != 1) && (item > h->element[i / 2])) {
		h->element[i] = h->element[i / 2];	//부모 노드는 자식 노드로 이동
		i /= 2;	//부모 노드로 검사범위 이동
	}
	h->element[i] = item;	//삽입 위치를 찾았으면 노드 삽입
}

//삭제 함수
int delete_heap(Heap* h) {
	int parent, child;
	int item, temp;
	item = h->element[1]; //루트 노드
	temp = h->element[(h->heap_size)--]; //빈 루트 노드 자리에 들어갈 히프의 마지막 노드
	parent = 1;
	child = 2;

	//히프 전체를 순회한다.
	while (child <= h->heap_size) {

		//자식노드 중 더 큰 자식노드를 찾는다.
		if ((child <= h->heap_size) && (h->element[child]) < h->element[child + 1]) {
			child++;
		}

		//만약 자식노드보다 현재 노드가 크다면 순회를 멈춘다.
		if (temp > h->element[child]) {
			break;
		}

		//검사 노드를 한 단계 아래로 이동
		h->element[parent] = h->element[child];
		parent = child;
		child *= 2;
	}
	h->element[parent] = temp;
	return item;
}

//히프 출력
void print_heap(Heap* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("[%d : %d] ",i, h->element[i]);
	}
}

int main() {
	Heap* h;
	h = create_heap();
	init_heap(h);
	srand((unsigned)time(NULL));
	int number;
	for (int i = 0; i < 15; i++) {
		number = rand() % 50 + 1;
		insert_heap(h, number);
	}
	print_heap(h);
	printf("\ndelete %d ",delete_heap(h));
	printf("\ndelete %d", delete_heap(h));
	printf("\ndelete %d", delete_heap(h));
	return 0;
}
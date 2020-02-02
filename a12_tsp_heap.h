#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100

typedef struct Node {
	int bound;	//현재 마디의 bound값
	int i;	//현재 마디의 수준
	int pt[10];	//현재 마디의 경로
}Node;

typedef Node element;

//히프
typedef struct {
	element data[MAX_SIZE]; //레코드
	int heap_size;	//힙 크기
}Heap;

Node create_node();
Heap* create_heap();
void init_heap(Heap* h);
void insert_heap(Heap* h, element item);
element delete_heap(Heap* h);


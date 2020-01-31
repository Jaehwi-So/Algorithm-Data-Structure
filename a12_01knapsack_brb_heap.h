#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 100
#define item_num 4
typedef struct TreeNode {
	int weight;
	int profit;
	int i;
	int bound;
} TreeNode;
typedef TreeNode element;
//히프
typedef struct {
	element data[MAX_SIZE]; //레코드
	int heap_size;	//힙 크기
}Heap;

Heap* create_heap();
void init_heap(Heap* h);
void insert_heap(Heap* h, element item);
element delete_heap(Heap* h);



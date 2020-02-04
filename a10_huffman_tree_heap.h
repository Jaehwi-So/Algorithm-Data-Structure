#define MAX_ELEMENT 200

//트리 노드
typedef struct TreeNode {
	int weight;	//빈도수
	char ch;	//문자
	struct TreeNode* left;	//왼쪽 자식
	struct TreeNode* right;	//오른쪽 자식
} TreeNode;	

//히프에 삽입될 단말노드
typedef struct {
	TreeNode* root;	//트리를 가리키는 포인터
	char ch;	//문자
	int key;	//빈도수
} element;

//히프
typedef struct {
	element data[MAX_ELEMENT];
	int heap_size;
} Heap;

Heap* create_heap();
void init_heap(Heap* h);
void insert_heap(Heap* h, element item);
element delete_heap(Heap* h);
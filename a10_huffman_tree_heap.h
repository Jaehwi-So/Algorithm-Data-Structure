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

// 생성 함수
Heap* create_heap();
// 초기화 함수
void init_heap(Heap* h);
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_heap(Heap* h, element item);
// 삭제 함수
element delete_heap(Heap* h);
//노드 정의
typedef struct Node {
	int key;	//키값
	struct Node* left;	//왼쪽 자식
	struct Node* right;	//오른쪽 자식
} Node;

int get_max(int a, int b);
int get_height(Node* node);
int get_balance(Node* node);
Node* create_node(int key);
Node* LL_rotate(Node* parent);
Node* RR_rotate(Node* parent);
Node* LR_rotate(Node* parent);
Node* RL_rotate(Node* parent);
Node* insert_node(Node* node, int key);



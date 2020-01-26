typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* first_insert_node(Node* head, int value);
Node* idx_insert_node(Node* head, Node* node, int value);
Node* first_delete_node(Node* head);
Node* idx_delete_node(Node* head, Node* node);
void print_node(Node* head);
Node* delete_node(Node* node, int index);
Node* insert_node(Node* node, int index, int value);

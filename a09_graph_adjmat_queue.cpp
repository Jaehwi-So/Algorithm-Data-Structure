#include "a09_graph_adjmat_queue.h"

int is_empty(Queuetype* q) {
	return q->front == q->rear;
}
int is_full(Queuetype* q) {
	return q->front == (q->rear + 1) % MAX_SIZE;
}

void init_queue(Queuetype* q) {
	q->front = 0;
	q->rear = 0;

}
void en_queue(Queuetype* q, int num) {

	if (is_full(q)) {
		printf("큐 포화 상태\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_SIZE;
	q->queue[q->rear] = num;
}
int de_queue(Queuetype* q) {

	if (is_empty(q)) {
		printf("큐 공백 상태\n");
		return -1;
	}
	q->front = (q->front + 1) % MAX_SIZE;
	return q->queue[q->front];

}
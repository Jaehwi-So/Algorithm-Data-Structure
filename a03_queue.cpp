//원형 큐 구현
//큐란 선입선출 방식(FIFO)를 따르며 선형 큐의 경우 배열의 공간을 효율적으로 사용하지 못하므로 주로 원형 큐를 이용한다.
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAX_QUEUE_SIZE 10  //큐 최대 사이즈
typedef int element;	
typedef struct queue{
	element data[MAX_QUEUE_SIZE];	//큐의 데이터 저장 배열
	int front;						//삭제시 index front
	int rear;						//삽입시 index rear
}Queue;

//큐 초기화
void init_queue(Queue *q){			
	q->front=0;
	q->rear=0;
}

//공백 검사
int is_empty(Queue *q){				//front와 rear가 같을 시 공백 상태
	return q->front==q->rear;

}

//포화 검사
int is_full(Queue *q){				
	return q->front==(q->rear+1)%MAX_QUEUE_SIZE;	//deque시의 index인 front 다음 index가 enqueue시의 index인 rear인 상태이면 포화 상태이다.
													//원형 큐 구현을 위해 최대 큐 사이즈로 %연산을 하여 최대 큐 사이즈를 넘어가게 되면 index가 0이 된다.
}


//enqueue
void en_queue(Queue *q, element item){
	if(is_full(q)){									//enque시 큐가 포화 상태이면 더이상 element를 삽입할 수 없다.
		printf("큐 포화 상태\n");
	}
	else{
	q->rear=((q->rear)+1)%MAX_QUEUE_SIZE;			//rear을 하나 증가 시킨 후 item을 삽입한다. 이때 원형큐를 구현하기 위해 %연산
	q->data[q->rear]=item;
	}

}

//dequeue
int de_queue(Queue *q){
	if(is_empty(q)){								//dequeue시 공백 상태이면 꺼낼 element가 없으므로 불가능하다.
		printf("큐 공백 상태\n");
	}
	else{
	q->front=(q->front+1)%MAX_QUEUE_SIZE;			//front를 하나 증가 시킨 후 큐에서 element를 꺼낸다. 이때 원형큐를 구현하기 위해 %연산
	return q->data[q->front];
	}

}
int main(){

	Queue queue;
	Queue* q1 = &queue;
	init_queue(q1);
	en_queue(q1,3);
	en_queue(q1,4);
	en_queue(q1,7);
	printf("%d ",de_queue(q1));
	printf("%d ",de_queue(q1));
	en_queue(q1,8);
	en_queue(q1,9);
	printf("%d ",de_queue(q1));	
	printf("%d ",de_queue(q1));
	system("pause");
	return 0;

}
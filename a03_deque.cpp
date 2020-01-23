//덱 구현
//덱은 큐의 front와 rear에서 모두 삽입과 삭제가 가능한 큐이다. 융통성이 많은 자료 구조이다.
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAX_QUEUE_SIZE 10  //덱에 사용할 큐의 최대 사이즈
typedef int element;	
typedef struct queue{
	element data[MAX_QUEUE_SIZE];	//큐의 데이터 저장 배열
	int front;						//전단부 front
	int rear;						//후단부 rear
}Deque;

//큐 초기화
void init_queue(Deque *q){			
	q->front=0;
	q->rear=0;
}

//공백 검사
int is_empty(Deque *q){				//front와 rear가 같을 시 공백 상태
	return q->front==q->rear;

}

//포화 검사
int is_full(Deque *q){				
	return q->front==(q->rear+1)%MAX_QUEUE_SIZE;	//rear 다음에 front가 있을 시 포화 상태이다.
													//원형 큐 구현을 위해 최대 큐 사이즈로 %연산을 하여 최대 큐 사이즈를 넘어가게 되면 index가 0이 된다.
}

//후단부 enqueue
void en_queue_rear(Deque *q, element item){
	if(is_full(q)){									//enqueue시 큐가 포화 상태이면 더이상 element를 삽입할 수 없다.
		printf("큐 포화 상태\n");
	}
	else{
	q->rear=((q->rear)+1)%MAX_QUEUE_SIZE;			//rear을 하나 증가 시킨 후 item을 삽입한다. 이때 원형큐를 구현하기 위해 %연산
	q->data[q->rear]=item;
	}

}
//전단부 enqueue
void en_queue_front(Deque *q, element item){
	if(is_full(q)){									//enqueue시 큐가 포화 상태이면 더이상 element를 삽입할 수 없다.
		printf("큐 포화 상태\n");
	}
	else{
	q->data[q->front]=item;
	q->front=(((q->front)-1)+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;	//front에서의 삽입연산 시 반대 방향의 회전이 필요하므로 1을 빼준다.
	}															//이 때 음수가 되는 것을 방지하기 위해서 MAX_QUEUE_SIZE를 더해준다.

}
//후단부 dequeue
element de_queue_rear(Deque *q){
	if(is_empty(q)){								//dequeue시 공백 상태이면 꺼낼 element가 없으므로 불가능하다.
		printf("큐 공백 상태\n");
	}
	else{
	int tmp = q->rear;
	q->rear=((q->rear-1)+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;			//rear에서의 삭제연산 시 반대방향의 회전이 필요하므로 1을 빼준다.
	return q->data[tmp];				
	}

}

//전단부 dequeue
element de_queue_front(Deque *q){
	if(is_empty(q)){								//dequeue시 공백 상태이면 꺼낼 element가 없으므로 불가능하다.
		printf("큐 공백 상태\n");
	}
	else{
	q->front=(q->front+1)%MAX_QUEUE_SIZE;			//front를 하나 증가 시킨 후 큐에서 element를 꺼낸다. 이때 원형큐를 구현하기 위해 %연산
	return q->data[q->front];
	}

}
int main(){

	Deque queue;
	Deque* q1 = &queue;
	init_queue(q1);
	en_queue_front(q1,1);
	en_queue_front(q1,2);
	en_queue_rear(q1,3);
	printf("%d ",de_queue_front(q1));
	printf("%d ",de_queue_rear(q1));
	printf("%d ",de_queue_front(q1));
	en_queue_rear(q1,4);
	en_queue_rear(q1,5);
    en_queue_front(q1,6);
	printf("%d ",de_queue_rear(q1));	
	printf("%d ",de_queue_front(q1));
	printf("%d ",de_queue_rear(q1));	
	system("pause");
	return 0;

}
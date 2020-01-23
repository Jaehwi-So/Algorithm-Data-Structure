#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX_STACK_SIZE  50

typedef int element;
typedef struct Stack{
	element data[MAX_STACK_SIZE];  
	int top;         //현재 스택의 top이 가리키는 곳.(push시 해당 element 다음으로 들어갈 곳, pop시 나갈 element)
}Stack;

//스택 초기화
void init_stack(Stack *s){
	s->top=-1;
}

//공백상태 확인
int is_empty(Stack *s){
	return ((s->top) == -1); // top이 -1이면 공백 상태임. true일시 1 반환
}

//포화상태 확인
int is_full(Stack *s){
	return ((s->top)==MAX_STACK_SIZE-1); //top이 스택 배열 index의 max값이라면 1 반환
}

//push
void push_stack(Stack *s, element item){
	if(is_full(s)){           //포화 상태일 경우 push 불가능
		printf("스택 포화");
		return;
	}
	else
	s->data[++(s->top)]=item;   //data 배열에서 top 다음 index에 해당하는 곳에 element를 push
}

//pop
element pop_stack(Stack *s){   //공백 상태일 경우 pop 불가능
	if(is_empty(s)){
		printf("스택 공백");
		exit(1);
	}
	else return s->data[(s->top)--]; //data 배열에서 top이 위치한 곳의 element를 pop
}


//피크 함수
element peek_stack(Stack *s){
	if(is_empty(s)){
		printf("스택 공백");
		exit(1);
	}
	else return s->data[(s->top)];
}


int main(){
	Stack s1;
	Stack *s = &s1;
	init_stack(s);
	push_stack(s,1);
	push_stack(s,2);
	push_stack(s,3);
	printf("pop %d\n", pop_stack(s));
	printf("pop %d\n", pop_stack(s));
	printf("pop %d\n", pop_stack(s));
	system("pause");
	return 0;

}
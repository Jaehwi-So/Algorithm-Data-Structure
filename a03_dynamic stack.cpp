/*동적 할당을 이용하여 스택을 생성하는 이유는 유연한 메모리 활용이 가능하기 때문이다. 프로그래머가 현재 스택의 MAX 사이즈가 얼마나 필요할 지
모르므로 동적 할당을 통해 유연하게 MAX조절을 가능하다는 장점이 있다.*/

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX_STACK_SIZE  50

typedef int element;
typedef struct Stack{
	element *data;  
	int capacity;    // 현재 크기
	int top;         //현재 스택의 top이 가리키는 곳.(push시 해당 element 다음으로 들어갈 곳, pop시 나갈 element)
}Stack;

//스택 초기화
void init_stack(Stack *s){
	s->top=-1;
	s->capacity=1;
	s->data = (element*)malloc(s->capacity*sizeof(element));
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
	if(is_full(s)){           //포화 상태일 경우 push 불가능하므로 stack의 size를 동적으로 늘여준다.		
		s->capacity *=2;
		s->data=(element*)realloc(s->data, s->capacity*sizeof(element));
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
	else return s->data[(s->top)--]; //data 배열에서 top이 위치한 곳의 element를 pop한다
}

int main(){
	Stack s;
	init_stack(&s);
	push_stack(&s,1);
	push_stack(&s,2);
	push_stack(&s,3);
	printf("pop %d\n", pop_stack(&s));
	printf("pop %d\n", pop_stack(&s));
	printf("pop %d\n", pop_stack(&s));
	free(s.data);
	system("pause");
	return 0;


}
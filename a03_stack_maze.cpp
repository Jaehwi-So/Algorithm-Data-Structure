#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX_STACK_SIZE  100
#define MAZE_SIZE  6

typedef struct element{
	int r_loc; //y좌표
	int c_loc; //x좌표

}element;

typedef struct Stack{
	element data[MAX_STACK_SIZE];  
	int top;         //현재 스택의 top이 가리키는 곳.(push시 해당 element 다음으로 들어갈 곳, pop시 나갈 element)
}Stack;

element here = {1,0};    //현재 위치의 좌표
element entry = {1,0};   //시작 위치의 좌표

//미로 maze
char maze[MAZE_SIZE][MAZE_SIZE]={
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','0','1'},
	{'0','0','1','1','0','x'},
	{'1','0','1','1','0','1'}
};

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
	else{
	s->data[++(s->top)]=item;   //data 배열에서 top 다음 index에 해당하는 곳에 element를 push
	}
}

//pop
element pop_stack(Stack *s){   //공백 상태일 경우 pop 불가능
	if(is_empty(s)){
		printf("스택 공백");
		exit(1);
	}
	else return s->data[(s->top)--]; //data 배열에서 top이 위치한 곳의 element를 pop
}


//현재 위치로부터 방문이 가능한 곳을 스택에 push한다.
void push_loc(Stack *s, int r, int c){
	if(r<0||c<0||r>=MAZE_SIZE||c>=MAZE_SIZE){     //push하려는 좌표가 MAZE 배열의 범위 밖이면 push하지 않는다.
		return;
	}
	if(maze[r][c] !='1'&& maze[r][c] !='.'){  //push하려는 곳이 막힌 곳(1)이거나 이미 탐색한 곳(.)이 아닌 경우 스택에 push한다.
		element temp;
		temp.r_loc=r;
		temp.c_loc=c;
		push_stack(s, temp);

	}

}


//maze 출력
void print_maze(char maze[MAZE_SIZE][MAZE_SIZE]){
	printf("\n");
	for(int r=0; r<MAZE_SIZE; r++){
		for(int c=0; c<MAZE_SIZE; c++){
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}

}
int main(){
	Stack s1;
	Stack *s = &s1;
	int r, c;
	init_stack(s);
	while(maze[here.r_loc][here.c_loc] !='x'){       //목적지 'x'를 찾을 때 깢.
		r=here.r_loc;			//현재 위치를 전에 pop된 좌표로 설정한다.
		c=here.c_loc;
		maze[r][c]='.';			//방문 표시를 한다.
		print_maze(maze);		
		push_loc(s, r,c+1);   //동쪽 push
		push_loc(s, r+1,c);   //남쪽 push
		push_loc(s, r,c-1);   //서쪽 push
		push_loc(s, r-1,c);   //북쪽 push
		//FILO이므로 pop될 때는 북서남동 순으로 탐색되게 된다.
		if(is_empty(s)){
			printf("\n실패");
			return 0;
		}
		else{
			here=pop_stack(s);  //다음 경로를 스택에서 pop한다.
		}

	}
	r=here.r_loc;
    c=here.c_loc;
	maze[r][c]='.';
	print_maze(maze);
	printf("\n성공");
	system("pause");
	return 0;
}

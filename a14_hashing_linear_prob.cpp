#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE	10	// 탐색키의 최대길이  
#define TABLE_SIZE	13	// 해싱 테이블의 크기 = 소수 

#define empty(a) (strlen(a.key)==0)
#define equal(a, b) (!strcmp(a.key,b.key))

typedef struct {
	char key[KEY_SIZE];	
} element;	//문자열

element hash_table[TABLE_SIZE];		//해싱 테이블 

void init_table(element table[]) {
	for (int i = 0; i < TABLE_SIZE; i++) {
		table[i].key[0] = NULL;
	}
}

//제산 함수로 해싱
int hash_function(char* key) {
	int number = 0;
	int idx = 0;
	while (key[idx] != NULL) {
		number = number + key[idx];
		idx++;
	}
	return number % TABLE_SIZE;	 //문자를 숫자로 변환 후 moduler 연산을 통하여 key값을 해싱한다.
}

//해싱 테이블 출력
void print_table(element table[]) {
	printf("-------------------------\n");
	for (int i = 0; i < TABLE_SIZE; i++)
		printf("[%d]  %s\n", i, table[i].key);
	printf("-------------------------\n");
}

//선형 조사법을 통해 키 삽입 해시 함수를 통해 얻어낸 해시값이 충돌이 일어나면 다음 버킷이 비어있는지 차례로 조사한다.
void linear_probing_insert(element item, element table[]) {
	int hash_value = hash_function(item.key);
	int i = hash_value;
	while (!empty(table[i])) {	//빈 버킷을 찾을 때 까지
		if (equal(item, table[i])) {
			fprintf(stderr, "탐색키 중복\n");
			exit(1);
		}
		i = (i + 1) % TABLE_SIZE;	//다음 버킷 조사
		if (i == hash_value) {	//전부 순회함
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
		}
	}
	table[i] = item;
	print_table(table);
}

// 선형조사법을 이용하여 테이블에 저장된 키를 탐색
void linear_probing_search(element item, element table[]) {
	int hash_value = hash_function(item.key);
	int i = hash_value;
	while (!empty(table[i])) {	//빈 버킷을 찾을 때 까지
		if (equal(item, table[i])) {	//key값이 일치한다면 탐색 성공
			fprintf(stderr, "key %s: index = %d\n", item.key, i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;	//다음 버킷 조사
		if (i == hash_value) {	//전부 순회함
			fprintf(stderr, "탐색 실패\n");
			return;
		}
	}
	fprintf(stderr, "탐색 실패\n");
}

int main(void) {
	char* s[7] = { "Red", "Yellow", "Orange", "Blue", "Green", "Purple", "Black" };
	element e;
	for (int i = 0; i < 7; i++) {
		strcpy(e.key, s[i]);
		linear_probing_insert(e, hash_table);
	}
	for (int i = 0; i < 7; i++) {
		strcpy(e.key, s[i]);
		linear_probing_search(e, hash_table);
	}
	return 0;
}
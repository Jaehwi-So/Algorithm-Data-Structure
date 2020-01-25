#include<stdio.h>
#include<stdlib.h>
#include "a06_ADTset01.h"

//Create : 집합을 생성해서 반환
SET* Create(void) {
	SET* s = (SET*)malloc(sizeof(SET));
	s->length = 0;
	return s;
}

//IsMember : 집합에 해당 원소가 존재한다면 index 반환, 그렇지 않으면 -1 반환
int IsMember(SET* set, int element) {
	for (int i = 0; i < set->length; i++) {
		if (set->data[i] == element) {
			return i;
		}
	}
	return -1;
}

//Size : 집합의 크기 반환
int Size(SET* set) {
	return set->length;
}

//Add : 집합에 원소 추가
void Add(SET* set, int element) {
	if (IsMember(set, element) == -1) {	//해당 원소가 집합의 원소가 아닐 때
		set->data[set->length++] = element;	//원소로 추가하고 집합의 크기 증가
	}
}

//Remove : 집합에서 원소 제거
void Remove(SET* set, int element) {
	if (IsMember(set, element) != -1) {	//해당 원소가 집합의 원소라면
		//집합에서 해당 원소의 index에 마지막 원소를 옮기고 해당 원소는 제거(집합의 크기 감소)
		set->data[IsMember(set, element)] = set->data[--(set->length)];	
	}
}

void Print(SET* set) {
	printf("{");
	for (int i = 0; i < set->length; i++) {
		if (i == set->length - 1) {
			printf("%d", set->data[i]);
		}
		else {
			printf("%d,", set->data[i]);
		}
	}
	printf("}\n");
}
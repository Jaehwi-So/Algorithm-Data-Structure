/*
#문제 : ADT Set, 집합을 정의하시오.
1)SET* Create(void) : 집합을 생성하여 반환
2)int IsMember(SET* set, int element) : 해당 원소가 집합에 포함되면 index 반환, 그렇지 않으면 -1 반환
3)int Size(SET* set) : 집합의 사이즈 반환
4)void Add(SET* set, int element) : 집합에 원소 추가
5)void Remove(SET* set, int element) : 집합에서 원소 제거
6)void Print(SET* set) : 집합의 모든 원소 출력
7)SET* Union(SET* set1, SET* set2) : 집합의 합집합을 반환
8)SET* Intersection(SET* set1, SET* set2) : 집합의 교집합을 반환
9)SET* Difference(SET* set1, SET* set2) : 집합의 여집합을 반환 (set1-set2)
*/

#include<stdio.h>
#include<stdlib.h>
#include "a06_ADTset01.h"
#include "a06_ADTset02.h"

void init_set(SET* set, int data[], int size) {
	for (int i = 0; i < size; i++) {
		Add(set, data[i]);
	}
}

int main() {
	SET* s1 = Create();
	SET* s2 = Create();
	int data1[7] = {1,3,5,6,7,9,13};
	int data2[7] = {2,3,5,8,11,13,15};
	init_set(s1, data1, 7);
	init_set(s2, data2, 7);
	printf("s1 : ");
	Print(s1);
	printf("s2 : ");
	Print(s2);

	SET* s3 = Create();
	SET* s4 = Create();
	SET* s5 = Create();
	s3 = Union(s1, s2);
	s4 = Intersection(s1, s2);
	s5 = Difference(s1, s2);
	printf("s1 U s2 : ");
	Print(s3);
	printf("s1 ∩ s2 : ");
	Print(s4);
	printf("s1 - s2 : ");
	Print(s5);
	return 0;
}
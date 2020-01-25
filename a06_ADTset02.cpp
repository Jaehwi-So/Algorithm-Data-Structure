#include "a06_ADTset02.h"

//Union : 두 집합의 합집합 반환
SET* Union(SET* set1, SET* set2) {
	SET* set = Create();
	for (int i = 0; i < set1->length; i++) {
		Add(set, set1->data[i]);	//set1의 집합을 set에 추가
	}
	for (int i = 0; i < set2->length; i++) {
		Add(set, set2->data[i]);	//set2의 집합을 set에 추가, 이 과정에서 중복인 것은 추가되지 않음
	}
	return set;
}

//Intersection : 두 집합의 교집합 반환
SET* Intersection(SET* set1, SET* set2) {
	SET* set = Create();
	for (int i = 0; i < set1->length; i++) {
		for (int j = 0; j < set2->length; j++) {
			if (set1->data[i] == set2->data[j]) { //set1과 set2의 모든 원소들을 하나씩 검사하여 중복인 것을 찾음
				Add(set, set1->data[i]);	//중복인 원소를 set에 추가
			}
		}
	}
	return set;
}

//Intersection : 두 집합의 차집합 반환(set1-set2)
SET* Difference(SET* set1, SET* set2) {
	SET* set = Create();
	for (int i = 0; i < set1->length; i++) {
		Add(set, set1->data[i]);	//set1의 원소를 set에 추가
	}
	for (int i = 0; i < set2->length; i++) {
		Remove(set, set2->data[i]);	//set에서 set2에 있는 원소를 제거
	}
	return set;
}
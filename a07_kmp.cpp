/*
# KMP법을 이용하여 문자열에서 문자열을 검색하고 몇번째에 있었는지 표시하기
*/
#include<stdio.h>

int kmp_scan(char* str, char* letter) {
	int str_p = 1;	//문자열을 검사할 포인터 
	int let_p = 0;	//패턴을 검사할 포인터
	int skip_p[1000]; //몇번째 문자부터 다시 검색할 지 skip판단

	//skip 판단을 위하여 패턴에서 중복지점 판단하기
	//이때는 str_p와 let_p가 다른 용도, 중복 판별을 위해 사용된다.
	skip_p[str_p] = 0;
	while (letter[str_p] != '\0') {	
		if (letter[str_p] == letter[let_p]) {	
			skip_p[++str_p] = ++let_p;
		}
		else if (let_p == 0) {
			skip_p[++str_p] = let_p;
		}
		else {
			let_p = skip_p[let_p];
		}
	}

	//문자열에서 검색
	str_p = 0;
	let_p = 0;
	while (str[str_p] != '\0' && letter[let_p] != '\0') {	//문자열과 패턴 둘다 끝에 도달할 때까지
		if (str[str_p] == letter[let_p]) {	//일치할 경우 두 문자열의 검사 포인터 이동
			str_p++;
			let_p++;
		}
		else if (let_p == 0) {	//일치하지 않지만 패턴검사 포인터가 0일 시 = 처음부터 틀린거.
			str_p++;	//문자열 검사 포인터를 이동
		}
		else {
			let_p = skip_p[let_p];	//아닐 경우 패턴검사 포인터를 skip지점으로 초기화
		}
	}
	if (letter[let_p] == '\0') {	//패턴이 끝까지 도달 = 문자열에서 일치
		return str_p - let_p;
	}
	return -1;


}

void str_search(char* str, char* letter) {
	int index;
	if ((index = kmp_scan(str, letter)) != -1) {
		printf("[%s]에서 [%s] 검색 성공, 위치 %d\n", str, letter, index + 1);
	}
	else {
		printf("[%s]에서 [%s] 검색 실패\n", str, letter);
	}

}
int main() {

	char* str = "For every dreamer, a dream were unstoppable";
	str_search(str, "unstoppable");
	str_search(str, "every dreamer");
	str_search(str, "dream");
	str_search(str, "waiting for love");

	//한글
	char* str2 = "별빛이 내려오지 마구 내려오지 경고";
	str_search(str2, "별빛");
	str_search(str2, "저 괴물체는 뭘까");
	str_search(str2, "마구 내려오지");
	str_search(str2, "내려오지 경고"); 
	return 0;


}
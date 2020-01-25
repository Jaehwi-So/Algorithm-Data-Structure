/*
# 브루트-포스법(Brute-Force Method)을 이용하여 문자열에서 문자열을 검색하고 몇번째에 있었는지 표시하기
*/
#include<stdio.h>

int bf_scan(char* str, char* letter) {//문자열과 찾을 패턴 입력
	int str_p = 0;	//문자열을 검사할 포인터 
	int let_p = 0;	//패턴을 검사할 포인터
	while (str[str_p] != '\0' && letter[let_p] != '\0') {	//문자열과 패턴 둘다 끝에 도달할 때까지
		if (str[str_p] == letter[let_p]) {	//일치할 경우 두 문자열의 검사 포인터 이동
			str_p++;
			let_p++;
		}
		else {
			str_p = str_p - let_p + 1;	//일치하지 않을 경우 검사 포인터 위치 재설정
			let_p = 0;	//패턴 검사 포인터를 다시 처음부터
		}
	}
	if (letter[let_p] == '\0') {	//패턴이 끝까지 도달 = 문자열에서 일치
		return str_p - let_p;
	}
	return -1;
}

void str_search(char* str, char* letter) {
	int index;
	if ((index=bf_scan(str, letter)) != -1) {
		printf("[%s]에서 [%s] 검색 성공, 위치 %d\n",str, letter, index+1);
	}
	else {
		printf("[%s]에서 [%s] 검색 실패\n",str, letter);
	}

}
int main() {

	char* str = "For every dreamer, a dream were unstoppable";
	str_search(str, "unstoppable");
	str_search(str, "every dreamer");
	str_search(str, "waiting for love");

	//한글
	char* str2 = "별빛이 내려오지 마구 내려오지";
	str_search(str2, "마구");
	str_search(str2, "저 괴물체는 뭘까");
	str_search(str2, "별빛이 내려오지");
	return 0;


}
/*
# Boyer_Moore법을 이용하여 문자열에서 문자열을 검색하고 몇번째에 있었는지 표시하기
*/
#include<stdio.h>
#include<string.h>
#include<limits.h>

int boyer_moore_scan(char* str, char* letter) {
	int str_p = 1;	//문자열을 검사할 포인터 
	int let_p = 0;	//패턴을 검사할 포인터
	int str_len = strlen(str);
	int let_len = strlen(letter);
	int skip_p[UCHAR_MAX+1]; //몇번째 문자부터 다시 검색할 지 skip판단

	//skip판단 index검사
	for (str_p = 0; str_p <= UCHAR_MAX; str_p++)			
		skip_p[str_p] = let_len;
	for (str_p = 0; str_p < let_len - 1; str_p++)
		skip_p[letter[str_p]] = let_len - str_p - 1;		

	//문자열 스캔
	int jump_str;
	while (str_p < str_len) {
		let_p = let_len - 1; 			
		while (str[str_p] == letter[let_p]) {
			if (let_p == 0)
				return str_p;
			let_p--;
			str_p--;
		}
		if (skip_p[str[str_p]] > let_len - let_p) {
			str_p += skip_p[str[str_p]];
		}
		else {
			str_p += let_len - let_p;
		}
	}
	return -1;


}

void str_search(char* str, char* letter) {
	int index;
	if ((index = boyer_moore_scan(str, letter)) != -1) {
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
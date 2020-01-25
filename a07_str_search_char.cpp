/*
#문제 : 문자열 "My String is the best" 에서 M, m ,B, a 문자가 있는지 검사하기
*/
#include<stdio.h>
#include<stdlib.h>

int scan_str(char* s, char c) {
	int i = 0;
	while (s[i] != c) {
		if (s[i] == '\0') {
			printf("%c 검색 실패\n", c);
			return -1;
		}
		i++;
	}
	printf("%c 검색 성공\n",c);
	return i;
}
int main() {
	char* str = "My String is the best";
	int ck;
	ck=scan_str(str, 'M');
	ck=scan_str(str, 'm');
	ck=scan_str(str, 'B');
	ck=scan_str(str, 'a');


	return 0;
}

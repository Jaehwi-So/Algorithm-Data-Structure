/*
bj_1152
문제
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 
이를 구하는 프로그램을 작성하시오. 
단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.
입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 
단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 
또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.
출력
첫째 줄에 단어의 개수를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char str[1000001];
	int i = 0;
	int num = 0;
	fgets(str, sizeof(str) - 1, stdin);
	str[strlen(str) - 1] = '\0';
	while (str[i] != '\0') {
		if (str[i] != ' '  && str[i] != '\0') {
			if (str[i + 1] == ' ' || str[i + 1] == '\0') {
				num++;
			}
		}
		i++;
	}
	printf("%d", num);
	return 0;
}
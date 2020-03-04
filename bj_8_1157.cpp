/*
bj_16114
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 
작성하시오.단, 대문자와 소문자를 구분하지 않는다.
입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.주어지는 단어의 길이는 1, 000, 000을 넘지 않는다.
출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.단, 가장 많이 사용된 알파벳이 여러 개 
존재하는 경우에는 ? 를 출력한다.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char str[1000001];
	fgets(str, sizeof(str) - 1, stdin);
	str[strlen(str) - 1] = '\0';

	int freq['Z' - 'A' +1];	//A~Z까지 빈도수 저장 배열

	for (int k = 0; k < 'Z' - 'A' + 1; k++) {	//빈도수 배열 초기화
		freq[k] = 0;
	}

	int i = 0;
	char c;


	//빈도수 체크
	while (str[i] != '\0') {
		c = str[i];
		if (c >= 97) {	//소문자일 경우 대문자로
			c -= 32;
		}
		freq[c-65]++;	
		i++;
	}

	int best_freq = 0;	//가장 많은 단어의 수
	char best = 'A';	//가장 많은 단어

	//가장 많이 사용된 알파벳 구하기
	for (int k = 0; k < 'Z' - 'A' + 1; k++) {
		if (freq[k] > best_freq) {
			best_freq = freq[k];
			best = (char)k + 65;
		}
	}

	//가장 많이 사용된 알파벳이 여러개 인지 체크
	for (int k = 0; k < 'Z' - 'A' + 1; k++) {
		if (freq[k] == best_freq && best != (char)k + 65) {
			best = '?';
			break;
		}
	}

	printf("%c", best);
	return 0;
}
/*
bj_1316
문제
그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우만을 말한다.예를 들면, 
ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나고, kin도 k, i, n이 연속해서 나타나기 때문에 그룹 단어이지만, 
aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아니다.
단어 N개를 입력으로 받아 그룹 단어의 개수를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 단어의 개수 N이 들어온다.N은 100보다 작거나 같은 자연수이다.둘째 줄부터 N개의 줄에 단어가 들어온다.
단어는 알파벳 소문자로만 되어있고 중복되지 않으며, 길이는 최대 100이다.
출력
첫째 줄에 그룹 단어의 개수를 출력한다.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//그룹 단어 판별
bool is_group(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if (i > 0) {
			if (str[i] != str[i - 1]) {	//같은 문자가 이어지지 않는 경우
				for (int k = 0; k < i; k++) {	//이전의 문자와 중복된 것이 있는지 검사
					if (str[i] == str[k]) {
						return false;	//그룹 단어가 아님
					}
				}
			}
		}
		i++;
	}
	return true;	//그룹 단어임
}
int main() {
	int n;
	int count = 0;

	//단어 수 입력
	scanf("%d", &n);
	
	char (*str)[101] = (char(*)[101])malloc(sizeof(char)*101*n);	//단어 배열 동적할당

	//단어 입력
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	//그룹 단어 수 체크
	for (int i = 0; i < n; i++) {
		if (is_group(str[i])) {
			count++;
		}
	}
	printf("%d",count);

	return 0;
}
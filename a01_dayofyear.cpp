//#8. 윤년 계산 : 몇 년, 몇 월, 몇 일을 입력받아 해당 해의 몇년째 되는 날인지 구하시오
#include<stdio.h>

//달마다의 날 수
int callender[12] = {31,28,31,30,31,30,31,31,30,31,30,31 };

//윤년 판단
int leap(int year) {
	return year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
}

//지난 날 계산
int count_day(int year, int month, int day) {
	//윤년일시, 2월의 날짜수 29로
	if (leap(year)) {
		callender[1]++;
	}
	int count=0;
	for (int i = 1; i < month; i++) {
		count += callender[i - 1];
	}
	count += day;
	return count;

}
int main() {
	int year, month, day;
	printf("몇년, 몇월, 며칠을 차례로 입력해주세요 : ");
	scanf("%d %d %d" ,&year, &month, &day);
	printf("해당 년도의 %d일 되는 날입니다." ,count_day(year, month, day));
	return 0;
}
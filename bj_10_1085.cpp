/*bj_1085
문제
한수는 지금(x, y)에 있다.직사각형의 왼쪽 아래 꼭짓점은(0, 0)에 있고, 오른쪽 위 꼭짓점은(w, h)에 있다.
직사각형의 경계선까지 가는 거리의 최솟값을 구하는 프로그램을 작성하시오.
입력
첫째 줄에 x y w h가 주어진다.w와 h는 1, 000보다 작거나 같은 자연수이고, 
x는 1보다 크거나 같고, w - 1보다 작거나 같은 자연수이고, 
y는 1보다 크거나 같고, h - 1보다 작거나 같은 자연수이다.
출력
첫째 줄에 문제의 정답을 출력한다.
*/
#include<stdio.h>
int main() {
	int x, y, w, h;
	int min, min_x, min_y;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	//현재 점에서 최소 x축 이동거리
	if (w - x > x) {
		min_x = x;
	}
	else {
		min_x = w - x;
	}
	//현재 점에서 최소 y축 이동거리
	if (h - y > y) {
		min_y = y;
	}
	else {
		min_y = h - y;
	}
	//x축 이동거리와 y축 이동거리 중 최소 이동거리
	if (min_x < min_y) {
		min = min_x;
	}
	else {
		min = min_y;
	}

	printf("%d", min);
	return 0;

}
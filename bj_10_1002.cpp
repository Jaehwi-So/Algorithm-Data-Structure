/*bj_1002
조규현과 백승환은 터렛에 근무하는 직원이다. 
하지만 워낙 존재감이 없어서 인구수는 차지하지 않는다. 다음은 조규현과 백승환의 사진이다.

이석원은 조규현과 백승환에게 상대편 마린(류재명)의 위치를 계산하라는 명령을 내렸다. 
조규현과 백승환은 각각 자신의 터렛 위치에서 현재 적까지의 거리를 계산했다.
조규현의 좌표 (x1, y1)와 백승환의 좌표 (x2, y2)가 주어지고, 
조규현이 계산한 류재명과의 거리 r1과 백승환이 계산한 류재명과의 거리 r2가 주어졌을 때, 
류재명이 있을 수 있는 좌표의 수를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 이루어져 있다.
한 줄에 x1, y1, r1, x2, y2, r2가 주어진다. x1, y1, x2, y2는 -10,000보다 크거나 같고, 
10,000보다 작거나 같은 정수이고, r1, r2는 10,000보다 작거나 같은 자연수이다.
출력
각 테스트 케이스마다 류재명이 있을 수 있는 위치의 수를 출력한다. 
만약 류재명이 있을 수 있는 위치의 개수가 무한대일 경우에는 -1을 출력한다.
*/
#include<stdio.h>
#include<math.h>
#define swap(X,Y,T) T=X; X=Y; Y=T
double get_dist(int x1, int y1, int x2, int y2) {
	return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int x1, y1, r1, x2, y2, r2, point;
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		/*
		(x1,y1)을 기준으로 반지름이 r1인 원과 (x2,y2)를 기준으로 반지름이 r2인
		원이 만들어지며 원이 만나는 지점이 류재명이 있을 수 있음
		case1 : 두 원이 일치하는 경우(-1)
		case2 : 내접하지 않으며 한 원이 다른 원을 포함하는 경우(0)
		case3 : 두 원이 내접하는 경우(1)
		case4 : 두 원이 두 점에서 만나는 경우(2)
		case5 : 두 원이 외접하는 경우(1)
		case6 : 두 원이 만나지 않는 경우(0)
		*/

		int tmp;
		if (r2 > r1) {	//반지름이 큰 원을 x1, y1, r1으로 한다.
			swap(x1, x2, tmp);
			swap(y1, y2, tmp);
			swap(r1, r2, tmp);
		}

		double dist = get_dist(x1, y1, x2, y2); //두 원의 중심의 좌표 사이의 거리

		if (dist == 0 && r1 == r2) {	//case1
			point = -1;
		}
		else if (dist > (r1 + r2) || dist + r2 < r1) {	//case2, case6
			point = 0;
		}
		else if (dist == (r1 + r2) || dist + r2 == r1) {	//case3, case5
			point = 1;
		}
		else if (dist < (r1 + r2) ) {	//case4
			point = 2;
		}
		printf("%d\n", point);
	}
	return 0;
}
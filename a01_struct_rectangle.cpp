/*
문제 : 
1)구조체를 활용하여, 직사각형 구조체 struct rectangle를 정의하라.
2)구조체 변수를 parameter로 입력받아, 넓이를 반환해주는 함수 area를 구현하시오.
3)구조체 변수를 parameter로 입력받아, 둘레길이를 반환해주는 함수 perimeter를 구현하시오.
4)구조체 변수를 parameter로 입력받아, 해당 직사각형이 정사각형인지의 여부를 반환(정사각형 : 1반환, 아니면 : 0반환)하는 함수 is_square를 구현하시오.
5) main함수에서 struct point 구조체 변수를 하나 선언하고, 2개의 점 좌표를 사용자에게 입력받고, 
2)~4) 함수를 활용하여, 직사각형의 넓이, 둘레길이, 정사각형인지의 여부를 출력하는 프로그램을 구현하시오.
*/

#include<stdio.h>
typedef struct rectangle
{
	double pos1;
	double pos2;

}rectangle;
double area(rectangle dot1, rectangle dot2) {

	double length1, length2;
	if (dot1.pos1 - dot2.pos1 > 0) {
		length1 = (dot1.pos1 - dot2.pos1);
	}
	else {
		length1 = -(dot1.pos1 - dot2.pos1);
	}

	if (dot1.pos2 - dot2.pos2 > 0) {
		length2 = (dot1.pos2 - dot2.pos2);
	}
	else {
		length2 = -(dot1.pos2 - dot2.pos2);
	}

	return length1 * length2;

}
double perimeter(rectangle dot1, rectangle dot2) {

	double length1, length2;
	if (dot1.pos1 - dot2.pos1 > 0) {
		length1 = (dot1.pos1 - dot2.pos1);
	}
	else {
		length1 = -(dot1.pos1 - dot2.pos1);
	}

	if (dot1.pos2 - dot2.pos2 > 0) {
		length2 = (dot1.pos2 - dot2.pos2);
	}
	else {
		length2 = -(dot1.pos2 - dot2.pos2);
	}

	return (length1 * 2) + (length2 * 2);

}
double is_square(rectangle dot1, rectangle dot2) {

	double length1, length2;
	if (dot1.pos1 - dot2.pos1 > 0) {
		length1 = (dot1.pos1 - dot2.pos1);
	}
	else {
		length1 = -(dot1.pos1 - dot2.pos1);
	}

	if (dot1.pos2 - dot2.pos2 > 0) {
		length2 = (dot1.pos2 - dot2.pos2);
	}
	else {
		length2 = -(dot1.pos2 - dot2.pos2);
	}

	if (length1 == length2) {
		return 1;
	}
	if (length1 != length2) {
		return 0;
	}


}



int main() {
	rectangle dot1, dot2;  //구조체 변수 선언
	printf("좌측 상단 점의 좌표 :");
	scanf("%lf %lf", &dot1.pos1, &dot1.pos2);
	printf("우측 하단 점의 좌표 :");
	scanf("%lf %lf", &dot2.pos1, &dot2.pos2);

	double rectanglearea = area(dot1, dot2);
	printf("넓이 %g \n", rectanglearea);
	double rectangleperimeter = perimeter(dot1, dot2);
	printf("둘레길이 %g \n", rectangleperimeter);
	if (is_square(dot1, dot2) == 1) {
		printf("정사각형 입니다.");
	}
	if (is_square(dot1, dot2) == 0) {
		printf("직사각형 입니다.");
	}

	return 0;


}
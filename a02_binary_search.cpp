/*이진 탐색
문제: 크기가 n인 정렬된 배열 S에 x가 있는가?
입력: (1) 양수 n, (2) 배열 S[1..n], (3) 키 x
출력: x가 S의 어디에 있는지의 위치. 만약 없으면, -1. 

*/
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define n    18
int S[n]={0,3,4,6,7,9,11,13,14,15,16,19,20,50,61,72,89,96};

int search_binary(int S[], int low, int high, int x){
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(x==S[mid]){
			return mid;
		}
		else if(x>S[mid]){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}

void printBinarySearch(int S[], int low, int high, int x){
	if(search_binary(S,low,high,x)!=-1){
		printf("이진 탐색 시작 : key : %d, result : index %d\n",x ,search_binary(S,low,high,x));
	}
	else{
		printf("이진 탐색 시작 : key : %d, result : ERROR\n",x);
	}

}
int main(){
	printBinarySearch(S,0,n-1,0);
	printBinarySearch(S,0,n-1,7);
	printBinarySearch(S,0,n-1,11);
	printBinarySearch(S,0,n-1,18);
	printBinarySearch(S,0,n-1,19);
	printBinarySearch(S,0,n-1,61);
	printBinarySearch(S,0,n-1,89);

	system("pause");
	return 0;


}
/*
	Chap07 Programming Assignment 풀이

	파일명 : Assign09.c
	문제 : 9. 1~12월의 핸드폰 요금을 배열에 저장하고 화면에 막대 그래프로 출력하는 프로그램을 작성하시오.
	12개월의 핸드폰 요금이 들어있는 배열을 특정 값으로 초기화해서 사용하고,
	핸드폰 요금 2000원 당 '*'를 하나씩 막대 그래프로 출력한다.

	작성일자 : 2025.09.16
*/

#include <stdio.h>
void phone();
void graph(int cost[], int size);

// 함수를 호출하고 정상적으로 프로그램을 종료하는 함수
int main()
{
	phone();
	return 0;
}

// 변수의 선언 및 초기화, 함수 호출을 통해 그래프를 출력하는 함수 
void phone()
{
	int cost[12] = { 36000, 42000, 38000, 37000, 40000, 41000, 35000, 50000, 51000, 45000, 42000, 65000 };
	int size = sizeof(cost) / sizeof(cost[0]);

	graph(cost, size);
}

// 그래프를 만들고 출력하는 함수
void graph(int cost[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int star = cost[i] / 2000; /*
									2000원당 '*'이 하나 출력된다는 점을 이용해
									출력할 '*'의 개수를 변수로 저장함
									*/
		int index = i + 1;

		printf("%d월 %d : ", index, cost[i]);

		for (int a = 0; a < star; a++)
		{
			printf("*");
		}
		printf("\n");
	}
}

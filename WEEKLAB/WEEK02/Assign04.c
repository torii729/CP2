/*
	Chap07 Programming Assignment 풀이

	파일명 : Assign04.c
	문제 : 4. 특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값을 가진 원소와
	최솟값을 가진 원소를 찾아서 인덱스와 값을 함께 출력하는 프로그램을 작성하시오.
	배열의 초기값은 마음대로 정하시오.

	작성일자 : 2025.09.16
*/

/*
	핵심 문제
	최댓값과 최솟값을 어떻게 알아낼 것인가?
	인덱스 출력하는 방법?
*/

#include <stdio.h>

void array();
void maxArray(int arrayInt[], int size);
void minArray(int arrayInt[], int size);
void printArray(int arrayInt[], int size);

// 함수를 호출하고 정상적으로 프로그램을 종료하는 함수
int main()
{
	array();
	return 0;
}

// 변수의 선언 및 초기화, 함수 호출을 통해 배열의 최댓값과 최솟값을 구하는 함수
void array()
{
	int arrayInt[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
	int size = sizeof(arrayInt) / sizeof(arrayInt[0]);

	printArray(arrayInt, size);
	maxArray(arrayInt, size);
	minArray(arrayInt, size);
}

// 배열을 출력하는 함수
void printArray(int arrayInt[], int size)
{
	printf("배열 : ");

	for (int n = 1; n < size; n++)
	{
		printf("%d ", arrayInt[n]);
	}
	printf("\n");
}

// 배열 속 최댓값을 찾는 함수
void maxArray(int arrayInt[], int size)
{
	int max = arrayInt[0];
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (arrayInt[i] > max)
		{
			max = arrayInt[i];
			maxIndex = i; /*
							0으로 초기화된 변수인 인덱스에 최댓값일 때의 반복변수를 대입하여
							최댓값일 때의 인덱스를 출력할 수 있다.
							*/
		}
	}

	printf("최댓값 : 인덱스 = %d, 값 = %d\n", maxIndex, max);
}

// 배열 속 최솟값을 찾는 함수
void minArray(int arrayInt[], int size)
{
	int min = arrayInt[0];
	int minIndex = 0;

	for (int j = 1; j < size; j++)
	{
		if (arrayInt[j] < min)
		{
			min = arrayInt[j];
			minIndex = j;
		}
	}

	printf("최솟값 : 인덱스 = %d, 값 = %d", minIndex, min);
}
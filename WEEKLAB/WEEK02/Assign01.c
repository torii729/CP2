/*
   Chap07 Programming Assignment 풀이

   파일명 : Assign01.c
   문제 : 1. 등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.
   크기가 10인 정수형 배열에 대하여 등차수열로 값을 채우려고 한다.
   첫 번째 항의 값과 공차(common difference)를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오.

   작성일자 : 2025.09.16
*/


#define ARR_SIZE 10
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fillCD(int arr[], int size, int start, int diff);
int Assign01();
void printArray(int arr[], int size);

// 함수 호출, Assign01 함수에서 나온 값을 반환함
int main()
{
    return Assign01();
}

int Assign01()
{
    int result[10] = { 0 };
    int start = 0;
    int diff = 0;

    // 입력하기
    printf("초기값 등차 입력하세요: ");
    scanf("%d %d", &start, &diff);

    // 계산하기
    fillCD(result, ARR_SIZE, start, diff);

    // 출력하기
    printArray(result, ARR_SIZE);
    return 0;
}

// 입력받은 초기값(첫째 항)과 등차를 이용하여 등차수열을 계산하는 함수 
void fillCD(int arr[], int size, int start, int diff)
{
    int i;

    arr[0] = start;

    for (i = 1; i < size; i++)
    {
        arr[i] = arr[i - 1] + diff;

    }
}

// 배열을 순서대로 출력하는 함수
void printArray(int arr[], int size)
{
    int i = 0;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
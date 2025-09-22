/*
    Chap07 Programming Assignment 풀이

    파일명 : Assign14.c
    문제 : 14. 음악 재생 프로그램에는 재생 목록에 있는 곡들을 임의의 순서로 뒤섞는 셔플 기능이 있다.
    이 셔플 기능처럼 크기가 10인 정수형 배열의 원소를 임의의 순서로 뒤섞는 프로그램을 작성하시오.
    크기가 10인 정수형 배열은 0~99사이의 임의의 정수로 채워서 테스트한다.

    작성일자 : 2025.09.16
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int arr[], int size); // 배열 초기화
void printArray(int arr[], int size); // 배열 출력
void shuffleArray(int arr[], int size); // 배열 섞기

int main()
{
    int arr[10] = { 0 };
    srand(time(NULL));

    initArray(arr, 10);
    printf("셔플 전 결과 : ");
    printArray(arr, 10);

    shuffleArray(arr, 10);
    printf("셔플 후 결과 : ");
    printArray(arr, 10);

    return 0;
}

// 배열 초기화
void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;  // 0~99 랜덤
    }
}

// 배열 출력
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 배열 섞기 rand() 함수를 통한
void shuffleArray(int arr[], int size)
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % size; // 나머지로 인덱스를 지정함 -> 진짜 랜덤으로 넣겠단 뜻
        int b = rand() % size;

        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}

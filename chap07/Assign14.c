/*
	음악 재생 프로그램에는 재생 목록에 있는 곡들을 임의의 순서로 뒤섞는 셔플 기능이 있다.
	이 셔플 기능처럼 크기가 10인 정수형 배열의 원소를 임의의 순서로 뒤섞는 프로그램을 작성하시오.
	크기가 10인 정수형 배열은 0~99사이의 임의의 정수로 채워서 테스트한다.

	작성일자 : 2025.09.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int arr[], int size); // 배열 초기화
void printArray(int arr[], int size); // 배열 출력
void shuffleArray(int arr[], int size); // 배열 섞기

int main()
{
    int arr[10];
    srand(time(NULL));

    initArray(arr, 10);
    printf("셔플 전 결과 : ");
    printArray(arr, 10);

    shuffleArray(arr, 10);
    printf("셔플 후 결과 : ");
    printArray(arr, 10);

    return 0;
}

void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;  // 0~99 랜덤
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void shuffleArray(int arr[], int size)
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % size;
        int b = rand() % size;

        int tmp = arr[a];
        arr[a] = arr[b];
        arr[b] = tmp;
    }
}

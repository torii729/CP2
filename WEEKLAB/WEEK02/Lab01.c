/*
    PPT 문제 풀이

	실수 배열에 대한 다음 두 함수를 구현하고
	printArrayFloat(float R[], int size)
	copyArrayFloat(float from[], float to[], int size)

	Test 함수를 작성하고 main에서 호출하여 실행해 보시오
	Int test_printArrayFloat()
	Int Test_copyArrayFloat()

	작성일자 : 2025.09.15
*/

#include <stdio.h>

void copyArrayFloat(float from[], float to[], int size);
void printArrayFloat(float R[], int size);
int test_copyArrayFloat();
int test_printArrayFloat();

int main()
{
    test_printArrayFloat();
    test_copyArrayFloat();
    return 0;
}

// 실수 배열 복사 함수
void copyArrayFloat(float from[], float to[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        to[i] = from[i];
    }
}

// 실수 배열 출력 함수
void printArrayFloat(float R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", R[i]);
    }
    printf("\n");
}

// 배열 복사 테스트 함수
int test_copyArrayFloat()
{
    float num_float[5] = { 1.0, 22.0, 333.0, 4444.0, 5555.0 };
    float null[5] = { 0 };

    copyArrayFloat(num_float, null, 5);

    printf("원본 배열 : ");
    printArrayFloat(num_float, 5);

    printf("복사된 배열 : ");
    printArrayFloat(null, 5);

    return 0;
}

// 배열 출력 테스트 함수
int test_printArrayFloat()
{
    float arr[5] = { 6.6, 7.7, 8.8, 9.9, 10.1 };

    printf("배열 출력 테스트 : ");
    printArrayFloat(arr, 5);

    return 0;
}
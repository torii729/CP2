/*
   Chap08 Programming Assignment 풀이

   파일명 : Assign15.c
   문제 : 15. 7장의 선택 정렬 코드를 이용해서 정수형 배열을 정렬하는 sort_array 함수를 정의하시오.
		크기가 10인 int 배열에 0~99 사이의 임의의 정수를 채운 다음 sort_array 함수로 정렬한 결과를 출력하는 프로그램을 작성.
   
   작성일자 : 2025.09.22
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test(void);
void sort_array(int a[], int n);

int main(void)
{
    test();
    return 0;
}

// 선택 정렬하는 함수
// i 자리를 확정하고, i 뒤쪽에서 가장 작은 값 위치 m을 찾아서 a[i]와 바꾸는 방식이다.
void sort_array(int a[], int n)
{
    int i = 0;

    for (i = 0; i < n - 1; i++)
    {
        int m = i; // 현재까지 본 것(for문을 통한 i) 중 가장 작은 값의 위치를 저장
        int j = 0;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[m])
            {
                m = j;
            }
        }

        if (m != i)
        {
            int tmp = a[i];
            a[i] = a[m];
            a[m] = tmp;
        }
    }
}

void test(void)
{
    int a[10] = { 0 };
    int n = 10;
    int i = 0;

    srand((unsigned)time(NULL)); // 그냥 랜덤 채우려고 시드를 넣는 것이다. 왜냐하면 프로그램을 실행할 때마다 다른 숫자가 나오게 하기 위해서다.

    // 0~99로 채움
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    printf("정렬 전: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    sort_array(a, n);

    printf("정렬 후: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

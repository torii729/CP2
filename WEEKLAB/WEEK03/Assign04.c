/*
   Chap08 Programming Assignment 풀이

   파일명 : Assign04.c
   문제 : 4. 배열 원소를 가리키는 포인터를 이용해서 실수형 배열의 평균을 구하는 프로그램. 실수형 배열은 크기가 10이고 마음대로 초기화한다.

   작성일자 : 2025.09.22
*/

#include <stdio.h>

void test(void);

int main(void)
{
    test();
    return 0;
}

// 포인터로 평균 구하는 함수
void test(void)
{
    double a[10] = { 0.10, 2.00, 3.40, 5.20, 4.50, 7.80, 9.70, 1.40, 6.60, 7.20 };
    int n = 10;
    double* p = a; // p는 배열의 첫 칸을 가리킨다.
    double sum = 0.0;
    int i = 0;

    // 배열 출력
    printf("배열: ");
    for (i = 0; i < n; i++)
    {
        printf("%.2f", a[i]);

        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    // *(p+i), 의미는 a[i]랑 똑같음
    for (i = 0; i < n; i++)
    {
        sum += *(p + i);
    }

    // 평균 = 합 / 개수이기 떄문에 double이라 소수점 유지
    printf("평균: %f\n", sum / n);
}

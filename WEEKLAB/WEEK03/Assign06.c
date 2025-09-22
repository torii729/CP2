/*
   Chap08 Programming Assignment 풀이

   파일명 : Assign06.c
   문제 : 6. 정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾는 get_min_max 함수를 정의하시오.
        크기가 10인 int 배열에 대해서 원하는 값으로 초기값을 채운 다음 get_min_max 함수로 최댓값과 최솟값을 찾아서 출력하시오.

   작성일자 : 2025.09.22
*/

#include <stdio.h>

void test(void);
void get_min_max(int a[], int n, int* pmax, int* pmin);

int main(void)
{
    test();
    return 0;
}

// 배열에서 가장 큰 값과 가장 작은 값을 찾아서 바깥 변수에 넣어준다
// pmax, pmin은 "결과를 적어줄 주소"이다.

void get_min_max(int a[], int n, int* pmax, int* pmin)
{
    int i = 0;

    if (n <= 0)
    {
        return;
    }

    // 시작값은 첫 칸으로 잡음
    *pmax = a[0];
    *pmin = a[0];

    // 1번 칸부터 끝까지 보면서 더 크면 큰 값 교체, 더 작으면 작은 값 교체
    for (i = 1; i < n; i++)
    {
        if (a[i] > *pmax)
        {
            *pmax = a[i];
        }
        if (a[i] < *pmin)
        {
            *pmin = a[i];
        }
    }
}

// 테스트 실행
void test(void)
{
    int a[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int n = 10;
    int maxv = 0;
    int minv = 0;
    int i = 0;

    printf("배열: ");
    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    get_min_max(a, n, &maxv, &minv);

    // &maxv는 "maxv를 보관하는 곳의 주소"이기 때문에 함수가 거기에 값을 적어주는...
    printf("최댓값: %d\n", maxv);
    printf("최솟값: %d\n", minv);
}

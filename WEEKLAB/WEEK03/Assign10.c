/*
   Chap08 Programming Assignment 풀이

   파일명 : Assign10.c
   문제 : 10. 3x3 행렬의 합을 구하는 add_matrix 함수 작성. 행렬로 사용될 2차원 배열은 마음대로 초기화해도 된다.
  
  작성일자 : 2025.09.22
*/

#include <stdio.h>

// 10번 실행
void test(void);
void add_matrix(int x[][3], int y[][3], int out[][3]);
void print_mat3(int m[][3], const char* title);

int main(void)
{
    test();
    return 0;
}

// out = x + y 계산함
// 왜 이중 for일까. 줄(행)을 돌고, 그 안에서 칸(열)을 반복한다. 3x3이라 i 0~2, j 0~2만큼..
void add_matrix(int x[][3], int y[][3], int out[][3])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            out[i][j] = x[i][j] + y[i][j];
        }
    }
}

// 보기 좋게 3x3 찍는 함수
void print_mat3(int m[][3], const char* title)
{
    int i = 0;
    int j = 0;

    printf("%s\n", title);
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void test(void)
{
    int x[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    int y[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    int z[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

    print_mat3(x, "x:");
    printf("\n");
    print_mat3(y, "y:");
    printf("\n");

    add_matrix(x, y, z);

    print_mat3(z, "x + y:");
}

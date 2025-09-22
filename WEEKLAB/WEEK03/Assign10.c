/*
   Chap08 Programming Assignment Ǯ��

   ���ϸ� : Assign10.c
   ���� : 10. 3x3 ����� ���� ���ϴ� add_matrix �Լ� �ۼ�. ��ķ� ���� 2���� �迭�� ������� �ʱ�ȭ�ص� �ȴ�.
  
  �ۼ����� : 2025.09.22
*/

#include <stdio.h>

// 10�� ����
void test(void);
void add_matrix(int x[][3], int y[][3], int out[][3]);
void print_mat3(int m[][3], const char* title);

int main(void)
{
    test();
    return 0;
}

// out = x + y �����
// �� ���� for�ϱ�. ��(��)�� ����, �� �ȿ��� ĭ(��)�� �ݺ��Ѵ�. 3x3�̶� i 0~2, j 0~2��ŭ..
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

// ���� ���� 3x3 ��� �Լ�
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

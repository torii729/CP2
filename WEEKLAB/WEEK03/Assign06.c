/*
   Chap08 Programming Assignment Ǯ��

   ���ϸ� : Assign06.c
   ���� : 6. ������ �迭�� ���Ͽ� �迭�� ���� �� �ִ񰪰� �ּڰ��� ã�� get_min_max �Լ��� �����Ͻÿ�.
        ũ�Ⱑ 10�� int �迭�� ���ؼ� ���ϴ� ������ �ʱⰪ�� ä�� ���� get_min_max �Լ��� �ִ񰪰� �ּڰ��� ã�Ƽ� ����Ͻÿ�.

   �ۼ����� : 2025.09.22
*/

#include <stdio.h>

void test(void);
void get_min_max(int a[], int n, int* pmax, int* pmin);

int main(void)
{
    test();
    return 0;
}

// �迭���� ���� ū ���� ���� ���� ���� ã�Ƽ� �ٱ� ������ �־��ش�
// pmax, pmin�� "����� ������ �ּ�"�̴�.

void get_min_max(int a[], int n, int* pmax, int* pmin)
{
    int i = 0;

    if (n <= 0)
    {
        return;
    }

    // ���۰��� ù ĭ���� ����
    *pmax = a[0];
    *pmin = a[0];

    // 1�� ĭ���� ������ ���鼭 �� ũ�� ū �� ��ü, �� ������ ���� �� ��ü
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

// �׽�Ʈ ����
void test(void)
{
    int a[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
    int n = 10;
    int maxv = 0;
    int minv = 0;
    int i = 0;

    printf("�迭: ");
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

    // &maxv�� "maxv�� �����ϴ� ���� �ּ�"�̱� ������ �Լ��� �ű⿡ ���� �����ִ�...
    printf("�ִ�: %d\n", maxv);
    printf("�ּڰ�: %d\n", minv);
}

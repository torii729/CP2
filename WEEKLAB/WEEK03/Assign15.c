/*
   Chap08 Programming Assignment Ǯ��

   ���ϸ� : Assign15.c
   ���� : 15. 7���� ���� ���� �ڵ带 �̿��ؼ� ������ �迭�� �����ϴ� sort_array �Լ��� �����Ͻÿ�.
		ũ�Ⱑ 10�� int �迭�� 0~99 ������ ������ ������ ä�� ���� sort_array �Լ��� ������ ����� ����ϴ� ���α׷��� �ۼ�.
   
   �ۼ����� : 2025.09.22
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

// ���� �����ϴ� �Լ�
// i �ڸ��� Ȯ���ϰ�, i ���ʿ��� ���� ���� �� ��ġ m�� ã�Ƽ� a[i]�� �ٲٴ� ����̴�.
void sort_array(int a[], int n)
{
    int i = 0;

    for (i = 0; i < n - 1; i++)
    {
        int m = i; // ������� �� ��(for���� ���� i) �� ���� ���� ���� ��ġ�� ����
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

    srand((unsigned)time(NULL)); // �׳� ���� ä����� �õ带 �ִ� ���̴�. �ֳ��ϸ� ���α׷��� ������ ������ �ٸ� ���ڰ� ������ �ϱ� ���ؼ���.

    // 0~99�� ä��
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    printf("���� ��: ");
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

    printf("���� ��: ");
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

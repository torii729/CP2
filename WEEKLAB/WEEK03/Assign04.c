/*
   Chap08 Programming Assignment Ǯ��

   ���ϸ� : Assign04.c
   ���� : 4. �迭 ���Ҹ� ����Ű�� �����͸� �̿��ؼ� �Ǽ��� �迭�� ����� ���ϴ� ���α׷�. �Ǽ��� �迭�� ũ�Ⱑ 10�̰� ������� �ʱ�ȭ�Ѵ�.

   �ۼ����� : 2025.09.22
*/

#include <stdio.h>

void test(void);

int main(void)
{
    test();
    return 0;
}

// �����ͷ� ��� ���ϴ� �Լ�
void test(void)
{
    double a[10] = { 0.10, 2.00, 3.40, 5.20, 4.50, 7.80, 9.70, 1.40, 6.60, 7.20 };
    int n = 10;
    double* p = a; // p�� �迭�� ù ĭ�� ����Ų��.
    double sum = 0.0;
    int i = 0;

    // �迭 ���
    printf("�迭: ");
    for (i = 0; i < n; i++)
    {
        printf("%.2f", a[i]);

        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    // *(p+i), �ǹ̴� a[i]�� �Ȱ���
    for (i = 0; i < n; i++)
    {
        sum += *(p + i);
    }

    // ��� = �� / �����̱� ������ double�̶� �Ҽ��� ����
    printf("���: %f\n", sum / n);
}

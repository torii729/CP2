/*
	PPT ���� Ǯ��

	���� 8-14 �� ������ Ÿ�Ե��� int ���� double �� �����ؼ� �ڵ��ϰ� �׽�Ʈ�ϱ�
*/

#include <stdio.h>

void get_sum_product(double x, double y, double* sum, double* product);

int main(void)
{
    double result1, result2;

    get_sum_product(10.5, 20.2, &result1, &result2);

    printf("sum = %.2f, product = %.2f\n", result1, result2);

    return 0;
}

void get_sum_product(double x, double y, double* sum, double* product)
{
    if (sum == NULL || product == NULL)
    {
        // NULL ������ üũ
        return;
    }

    *sum = x + y;
    *product = x * y;
}
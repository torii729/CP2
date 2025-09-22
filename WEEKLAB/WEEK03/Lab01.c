/*
	PPT ���� Ǯ��

	���� 8-13 �� ������ Ÿ�Ե��� int ���� double �� �����ؼ� �ڵ��ϰ� �׽�Ʈ�ϱ�
	void * swap(double * a, double * b)
	��, �����Ͱ� NULL���� �׽�Ʈ�� ��
	��ȯ ��: a �Ǵ� b �����Ͱ� NULL�̸� NULL, �׷��� ������ a ���� ��ȯ
*/

#include <stdio.h>

void* swap(double* a, double* b);

int main(void)
{
    double x = 3.3, y = 7.7;

    printf("�� : x = %.1f, y = %.1f\n", x, y);

    // ���� ��ȯ
    if (swap(&x, &y) == NULL)
        printf("���� ����\n");
    else
        printf("�� :  x = %.1f, y = %.1f\n", x, y);

    // NULL �׽�Ʈ
    if (swap(NULL, &y) == NULL)
        printf("���� ����\n");

    return 0;
}

void* swap(double* a, double* b)
{
    if (a == NULL || b == NULL)  // NULL ������ üũ
        return NULL;

    double temp = *a;
    *a = *b;
    *b = temp;

    return a;   // ���� ����: a ��ȯ
}
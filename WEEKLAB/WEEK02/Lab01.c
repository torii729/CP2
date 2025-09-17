/*
	�Ǽ� �迭�� ���� ���� �� �Լ��� �����ϰ�
	printArrayFloat(float R[], int size)
	copyArrayFloat(float from[], float to[], int size)

	Test �Լ��� �ۼ��ϰ� main���� ȣ���Ͽ� ������ ���ÿ�
	Int test_printArrayFloat()
	Int Test_copyArrayFloat()

	�ۼ����� : 2025.09.15
*/

#include <stdio.h>

void copyArrayFloat(float from[], float to[], int size);
void printArrayFloat(float R[], int size);
int test_copyArrayFloat();
int test_printArrayFloat();

int main()
{
    test_printArrayFloat();
    test_copyArrayFloat();
    return 0;
}

// �Ǽ� �迭 ���� �Լ�
void copyArrayFloat(float from[], float to[], int size)
{
    for (int i = 0; i < size; i++) 
    {
        to[i] = from[i];
    }
}

// �Ǽ� �迭 ��� �Լ�
void printArrayFloat(float R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.1f ", R[i]);
    }
    printf("\n");
}

// �迭 ���� �׽�Ʈ �Լ�
int test_copyArrayFloat()
{
    float num_float[5] = { 1.0, 22.0, 333.0, 4444.0, 5555.0 };
    float null[5] = { 0 };

    copyArrayFloat(num_float, null, 5);

    printf("���� �迭 : ");
    printArrayFloat(num_float, 5);

    printf("����� �迭 : ");
    printArrayFloat(null, 5);

    return 0;
}

// �迭 ��� �׽�Ʈ �Լ�
int test_printArrayFloat()
{
    float arr[5] = { 6.6, 7.7, 8.8, 9.9, 10.1 };

    printf("�迭 ��� �׽�Ʈ : ");
    printArrayFloat(arr, 5);

    return 0;
}
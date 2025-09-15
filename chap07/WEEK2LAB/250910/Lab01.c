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


int main()
{
    test_printArrayFloat();
    test_copyArrayFloat();
    return 0;
}

// �Ǽ� �迭 ��� �Լ�
void printArrayFloat(float R[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", R[i]);
    }
    printf("\n");
}

// �Ǽ� �迭 ���� �Լ�
void copyArrayFloat(float from[], float to[], int size) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}

// �迭 ��� �׽�Ʈ �Լ�
int test_printArrayFloat() {
    float arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    printf("test_printArrayFloat ���: ");
    printArrayFloat(arr, 5);
    return 0;   // ���� ����
}

// �迭 ���� �׽�Ʈ �Լ�
int test_copyArrayFloat() {
    float src[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
    float dst[5];
    copyArrayFloat(src, dst, 5);

    printf("���� �迭: ");
    printArrayFloat(src, 5);
    printf("����� �迭: ");
    printArrayFloat(dst, 5);

    return 0;   // ���� ����
}
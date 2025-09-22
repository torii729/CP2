/*
	PPT ���� Ǯ��

	void printArrayInt(const int* arr, int size)
		������ ++ �����ڸ� �̿��Ͽ� �����ϰ� �׽�Ʈ
		�� �����Ͱ� NULL���� Ȯ���� ��
	void printArrayInt2(const int arr[], int size)
		�迭 �ε����� �̿��Ͽ� �����ϰ� �׽�Ʈ
	int copyArrayFloat(const float* from, float* to, int size)
		������ ++�����ڸ� �̿��Ͽ� �����ϰ� �׽�Ʈ
		��ȯ : size
		�� �����͵��� NULL���� Ȯ���� ��
*/

/*
    void printArrayInt(const int* arr, int size)
       - ������ ++ �����ڷ� ��ȸ
       - arr�� NULL�̰ų� size <= 0�̸� �ȳ� ��� �� ��ȯ�Ѵ�.

    void printArrayInt2(const int arr[], int size)
       - �迭 �ε����� ��ȸ
       - arr�� NULL�̰ų� size <= 0�̸� �ȳ� ��� �� ��ȯ�Ѵ�.

    int copyArrayFloat(const float* from, float* to, int size)
       - ������ ++ �����ڷ� �����Ѵ�.
       - ������/size ����
       - ���� �� size ��ȯ, ���� �� 0 ��ȯ�Ѵ�.
*/

#include <stdio.h> // ǥ�� ����� ���

// ��� �Լ� �����
void printArrayInt(const int* arr, int size); // ������ ++�� int �迭 �����
void printArrayInt2(const int arr[], int size); // �ε����� int �迭 ����Ѵ�.
int  copyArrayFloat(const float* from, float* to, int size); // ������ ++�� float �迭 ������. �����ϸ� size ��ȯ�Ѵ�.

// �׽�Ʈ �Լ� �����
void test_all(void); // ��ü ���� �� ���� ������ ����

int main(void) // ������ ȣ�⸸ ��
{
    test_all(); // �׽�Ʈ �����Ѵ�.
    return 0; // ���� ������
}

// ������ ++�� int �迭 ����ϴ� �Լ�
void printArrayInt(const int* arr, int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("printArrayInt �Լ� �迭 ���� �Ǵ� ũ�� 0\n"); // ���� ������
        return;
    }

    const int* p = arr; // ���� ��ȣ�� ���� ������ ��
    for (int i = 0; i < size; i++, p++)
    {
        printf("%d ", *p); // p ������Ű�� �������� �� ����Ѵ�.
    }
    printf("\n"); // �ٹٲ� �����
}

// �ε����� int �迭 ����ϴ� �Լ�
void printArrayInt2(const int arr[], int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("printArrayInt2 �Լ� �迭 ���� �Ǵ� ũ�� 0\n"); // ���� ����
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // �ε����� �� ������ �����
    }
    printf("\n"); // �ٹٲ� �Ѵ�.
}

// ������ ++�� float �迭 ������
int copyArrayFloat(const float* from, float* to, int size)
{
    if (from == NULL || to == NULL || size <= 0)
    {
        return 0; // ���� �����Ѵ�. ���� �Ҹ��� �� ���з� ó����
    }

    const float* pf = from; // �б� ������. const ���������ν� �б� ����
    float* pt = to; // ���� ������
    for (int i = 0; i < size; i++, pf++, pt++)
    {
        *pt = *pf; // ���� ������ �����Ѵ�.
    }

    return size; // ���� ���� ��ȯ��
}

// ��ü ��� �׽�Ʈ�ϴ� �Լ�
void test_all(void)
{
    int ai[5] = { 10, 20, 30, 40, 50 }; // ���� �迭 �غ�
    printf("printArrayInt �Լ��� ptr++  : ");
    printArrayInt(ai, 5); // ������ ++ ��� Ȯ��

    printf("printArrayInt2 �Լ��� index : ");
    printArrayInt2(ai, 5); // �ε��� ��� Ȯ��


    float src[4] = { 1.1f, 2.2f, 3.3f, 4.4f }; // ���� ���� �غ�
    float dst[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; // ���� ������ �ʱ�ȭ

    int copied = copyArrayFloat(src, dst, 4); // ���� �õ�
    if (copied == 4)
    {
        printf("copyArrayFloat �Լ� : %d, dst : ", copied); // ���� �޽��� ���

        const float* p = dst; // ��� Ȯ�ο� ������
        for (int i = 0; i < 4; i++, p++)
        {
            printf("%.1f ", *p); // ������ ++�� ��� ���
        }
        printf("\n"); // �ٹٲ� ���
    }
    else
    {
        printf("copyArrayFloat ���� : %d\n", copied); // ���� �޽��� ���
    }

    printf("printArrayInt(NULL, 3) ��� : ");
    printArrayInt(NULL, 3); // NULL ���� ��� ���� Ȯ��

    printf("printArrayInt2(NULL, 0) ��� : ");
    printArrayInt2(NULL, 0); // NULL + size 0 ���� Ȯ��

    printf("copyArrayFloat(NULL, dst, 4)�� ��ȯ : %d\n", copyArrayFloat(NULL, dst, 4)); // from NULL ó�� Ȯ����
    printf("copyArrayFloat(src, NULL, 4)�� ��ȯ :% d\n", copyArrayFloat(src, NULL, 4)); // to NULL ó�� Ȯ����
    printf("copyArrayFloat(src, dst, 0)�� ��ȯ : %d\n", copyArrayFloat(src, dst, 0)); // size 0 ó�� Ȯ����
}

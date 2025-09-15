/*
	�迭 ���� �� �ּҰ� ã�� �Լ� :
	int findMinInt(int R[], int from, int to) : from���� to���� �ּҰ��� ���� �ε��� �ϳ��� ��ȯ

	�迭�� �� ���Ҹ� ��ȯ�ϱ� :
	void swapInt(int R[], int aindex, int bindex)

	�� �Լ��� �����ϰ�, �̸� �̿��� �������� �Լ��� ����
	Int selectionSortInt(int R[], int length) : ���� 0, ���� 0�� �ƴ� ��

	�׽�Ʈ �ڵ�
	�� �����ϴ��� �����ϴ� �Լ��� �ۼ��ϰ� main���� ȣ��
	Int test_selectionSortInt(void) : ���� 0, ���� 0�� �ƴ� ��
	������ ���� �迭�� ������ �� �����ϰ�, ���� �迭�� ���ĵ� ����� ���
	
	�ۼ����� : 2025.09.15
*/

#include <stdio.h>

int main()
{
    test_selectionSortInt();
    return 0;
}

// Ư�� �������� �ּҰ��� �ε��� ��ȯ
int findMinInt(int R[], int from, int to)
{
    int minIndex = from;
    for (int i = from + 1; i <= to; i++) 
    {
        if (R[i] < R[minIndex]) 
        {
            minIndex = i;
        }
    }
    return minIndex;
}

// �迭�� �� ���� ��ȯ
void swapInt(int R[], int aindex, int bindex)
{
    int temp = R[aindex];
    R[aindex] = R[bindex];
    R[bindex] = temp;
}

// ���� ���� �Լ�
int selectionSortInt(int R[], int length)
{
    for (int i = 0; i < length - 1; i++) 
    {
        int minIndex = findMinInt(R, i, length - 1);
        if (minIndex != i)
        {
            swapInt(R, i, minIndex);
        }
    }
    return 0;
}

// ���� ���� �׽�Ʈ �Լ�
int test_selectionSortInt(void)
{
    int arr[8] = { 64, 25, 12, 22, 11, 90, 55, 3 };
    int length = 8;

    printf("���� �迭: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = selectionSortInt(arr, length);

    printf("���ĵ� �迭: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


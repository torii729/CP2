/*
	���� ��� ���α׷����� ��� ��Ͽ� �ִ� ����� ������ ������ �ڼ��� ���� ����� �ִ�.
	�� ���� ���ó�� ũ�Ⱑ 10�� ������ �迭�� ���Ҹ� ������ ������ �ڼ��� ���α׷��� �ۼ��Ͻÿ�.
	ũ�Ⱑ 10�� ������ �迭�� 0~99������ ������ ������ ä���� �׽�Ʈ�Ѵ�.

	�ۼ����� : 2025.09.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initArray(int arr[], int size); // �迭 �ʱ�ȭ
void printArray(int arr[], int size); // �迭 ���
void shuffleArray(int arr[], int size); // �迭 ����

int main()
{
    int arr[10] = { 0 };
    srand(time(NULL));

    initArray(arr, 10);
    printf("���� �� ��� : ");
    printArray(arr, 10);

    shuffleArray(arr, 10);
    printf("���� �� ��� : ");
    printArray(arr, 10);

    return 0;
}

// �迭 �ʱ�ȭ
void initArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;  // 0~99 ����
    }
}

// �迭 ���
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// �迭 ���� rand() �Լ��� ����
void shuffleArray(int arr[], int size)
{
    for (int i = 0; i < 100; i++)
    {
        int a = rand() % size; // �������� �ε����� ������ -> ��¥ �������� �ְڴ� ��
        int b = rand() % size;

        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}

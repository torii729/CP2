/*
    2025.09.17~
    chap08 ������ ���� �ǽ�
*/
#include <stdio.h>

void menu();
void test_swap_double();
void* swapDouble(double* a, double* b);
int test_print_array();
void print_array_double(double arr[], int sz);
void printArrayDouble(double* arr, int sz);

int main()
{
    menu();
    return 0;
}

void menu()
{
    while (1)
    {
        int choice = 0;

        printf("1. ����\n2. �迭 ���\n3. ����\n� �Լ��� �����ϰڽ��ϱ�? : ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            test_swap_double();
        }
        else if (choice == 2)
        {
            test_print_array();
        }
        else if (choice == 3)
        {
            printf("\n�����մϴ�.");
            break;
        }
        else
        {
            printf("\n�ٽ� �Է����ּ���.");
        }
    }
}

void test_swap_double()
{
    double x = 3.3, y = 6.6;

    // 1. x, y�� ������ �ѱ�
    double* pre = (double*)swapDouble(&x, &y);
    if (pre == NULL)
    {
        printf("pre ���� : null\n");
    }
    else
    {
        printf("��� : a = %.1f, b = %.1f\n", x, y);
    }

    // 2. null�� ������?
    pre = swapDouble((double*)NULL, &y); // NULL�� �Ѱ�� ������ pre == NULL�� �ȴ�. �翬�� ����� ��µ��� �ʴ´�.
    if (pre == NULL)
    {
        printf("pre ������ ���� NULL�Դϴ�.\n\n");
    }
    else
    {
        printf("��� : a = %.1f, b = %.1f\n\n", x, y);
    }
}

// ���� �� ���� �ٲٴ� �Լ�(����)
void* swapDouble(double* a, double* b) // ��ȯ Ÿ���� �������� �Լ� ����
{
    // �Է� ���� �������� üũ�Ѵ�(NULL�� �ƴϾ�� �Ѵ�)
    if (a == NULL || b == NULL)
    {
        return NULL; // NULL �����͸� �����Ѵ�(�ƹ� �͵� ���� �� ����Ű�� �װ��� ��ȿ�� �޸� �ּҰ� �ƴϴ�)
    }

    // �����Ѵ�. ������ ���� temp�� a�� ����Ű�� ���� �־� �����ϴ� ��. �̶� a, b�� Ÿ���� ���ƾ� �Ѵ�.
    double temp = *a;
    *a = *b;
    *b = temp;

    return a;
}

// �迭�� ����ϴ� �Լ�, ���� ������ return 1, ���� ������ return 0.
int test_print_array()
{
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]); // ��ü / ù��° ����

    print_array_double(arr, size); // �迭 �̸�
    printArrayDouble(&arr[0], size); // ������(����Ų��), �迭�� ù��° ������ �ּҸ� �Ű������μ� ������ �Ѵ�.

    return 0;
}

/*
    ��� : 1���� �Ǽ� �迭�� �Է� �޾Ƽ� �ֿܼ� ����Ѵ�.
    �Լ��� : print_array_double(�迭 ���), printArrayDouble(������ ���)
    �Է� : double Ÿ�� 1���� �迭 �ּ�
    ��� : �͹̳ο� �迭�� ������ ���ڰ� ����Ѵ�.
    ��ȯ : ����
*/
void print_array_double(double arr[], int sz)
{
    printf("�迭�� ��� : ");
    for (int i = 0; i < sz; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void printArrayDouble(double *arr, int sz)
{
    printf("�����͸� ��� : ");
    for (int i = 0; i < sz; i++, arr++)
    {
        printf("%.1f ", *arr);
    }
    printf("\n\n");
}
/*
	����ü Ÿ���� �ϳ� ���Ƿ� ���� : ��) ����ó(�̸�, ��ȭ��ȣ, �޸�)
	typedef struct _contact { char name[64]; char phone1[24] } Contact;

	����ü �迭�� ���� ���� �� �Լ��� �����ϰ�
	void printArrayContact(Contact R[], int size)
	void copyArrayContact(Contact from[], Contact to[], int size)

	Test �Լ��� �ۼ��ϰ� main ���� ȣ���Ͽ� ������ ���ÿ�
	Int test_printArrayContact()
	Int Test_copyArrayContact()

	�ۼ����� : 2025.09.15
*/

#include <stdio.h>
#include <string.h>
#include "struct.h"

void copyArrayContact(Contact from[], Contact to[], int size);
void printArrayContact(Contact R[], int size);
int test_copyArrayContact();
int test_printArrayContact();

int main()
{
    test_printArrayContact();
    test_copyArrayContact();
    return 0;
}

// ����ü �迭 ���� �Լ�
void copyArrayContact(Contact from[], Contact to[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        to[i] = from[i];
    }
}


// ����ü �迭 ��� �Լ�
void printArrayContact(Contact R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("�̸� : %s, ��ȭ��ȣ : %s\n", R[i].name, R[i].phone1);
    }
    printf("\n");
}


// ���� �׽�Ʈ �Լ�
int test_copyArrayContact()
{
    Contact arr[2] = {
        {"�̼�", " 010-1234-5678"},
        {"����",   "010-9876-5432"}
    };

    Contact null[2] = { 0 };

    copyArrayContact(arr, null, 2);

    printf("���� �迭 : \n");
    printArrayContact(arr, 2);

    printf("����� �迭 : \n");
    printArrayContact(null, 2);

    return 0;
}

// ��� �׽�Ʈ �Լ�
int test_printArrayContact() 
{
    Contact arr[3] = {
        {"�α�", "010-1111-2222"},
        {"ö��", "010-3333-4444"},
        {"���", "010-5555-6666"}
    };

    printf("��� : \n");
    printArrayContact(arr, 3);

    return 0;
}
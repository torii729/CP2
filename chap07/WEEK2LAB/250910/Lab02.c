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

// ����ü Ÿ�� ����
typedef struct _contact {
    char name[64];
    char phone1[24];
} Contact;

// ����ü �迭 ��� �Լ�
void printArrayContact(Contact R[], int size) {
    for (int i = 0; i < size; i++) {
        printf("�̸�: %s, ��ȭ��ȣ: %s\n", R[i].name, R[i].phone1);
    }
    printf("\n");
}

// ����ü �迭 ���� �Լ�
void copyArrayContact(Contact from[], Contact to[], int size) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];   // ����ü ������ ��� ������ �ڵ� �����
    }
}

// ��� �׽�Ʈ �Լ�
int test_printArrayContact() {
    Contact arr[3] = {
        {"ȫ�浿", "010-1111-2222"},
        {"��ö��", "010-3333-4444"},
        {"�̿���", "010-5555-6666"}
    };

    printf("test_printArrayContact ���:\n");
    printArrayContact(arr, 3);
    return 0;
}

// ���� �׽�Ʈ �Լ�
int test_copyArrayContact() {
    Contact src[2] = {
        {"Alice", "010-1234-5678"},
        {"Bob",   "010-9876-5432"}
    };
    Contact dst[2];

    copyArrayContact(src, dst, 2);

    printf("���� �迭:\n");
    printArrayContact(src, 2);

    printf("����� �迭:\n");
    printArrayContact(dst, 2);

    return 0;
}

int main() {
    test_printArrayContact();
    test_copyArrayContact();
    return 0;
}

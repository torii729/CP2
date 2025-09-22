/*
    PPT 문제 풀이

	구조체 타입을 하나 임의로 선언 : 예) 연락처(이름, 전화번호, 메모)
	typedef struct _contact { char name[64]; char phone1[24] } Contact;

	구조체 배열에 대한 다음 두 함수를 구현하고
	void printArrayContact(Contact R[], int size)
	void copyArrayContact(Contact from[], Contact to[], int size)

	Test 함수를 작성하고 main 에서 호출하여 실행해 보시오
	Int test_printArrayContact()
	Int Test_copyArrayContact()

	작성일자 : 2025.09.15
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

// 구조체 배열 복사 함수
void copyArrayContact(Contact from[], Contact to[], int size) 
{
    for (int i = 0; i < size; i++)
    {
        to[i] = from[i];
    }
}


// 구조체 배열 출력 함수
void printArrayContact(Contact R[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("이름 : %s, 전화번호 : %s\n", R[i].name, R[i].phone1);
    }
    printf("\n");
}


// 복사 테스트 함수
int test_copyArrayContact()
{
    Contact arr[2] = {
        {"이서", " 010-1234-5678"},
        {"서연",   "010-9876-5432"}
    };

    Contact null[2] = { 0 };

    copyArrayContact(arr, null, 2);

    printf("원본 배열 : \n");
    printArrayContact(arr, 2);

    printf("복사된 배열 : \n");
    printArrayContact(null, 2);

    return 0;
}

// 출력 테스트 함수
int test_printArrayContact() 
{
    Contact arr[3] = {
        {"민기", "010-1111-2222"},
        {"철수", "010-3333-4444"},
        {"기민", "010-5555-6666"}
    };

    printf("결과 : \n");
    printArrayContact(arr, 3);

    return 0;
}
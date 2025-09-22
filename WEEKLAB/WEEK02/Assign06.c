/*
	Chap07 Programming Assignment 풀이

	파일명 : Assign06.c
	문제 : 6. 크기가 10인 실수형 배열에 대해서 원소들을 역순으로 만드는 프로그램을 작성하시오.
	실수형 배열의 초기값은 마음대로 정하시오.

	작성일자 : 2025.09.16
*/

#include <stdio.h>

void array();
void printArray(double arrayDouble[], int size);
void ArrayRe(double arrayDouble[], int size);

// 함수를 호출하고 프로그램을 정상적으로 종료하는 함수
int main()
{
	array();
	return 0;
}

/*
	변수의 선언 및 초기화, 함수의 호출을 통해 원래 배열을 출력하고
	역순 배열을 받아와 역순 배열을 출력하는 함수
*/
void array()
{
	double arrayDouble[10] = { 1.2, 3.1, 4.3, 4.5, 6.7, 2.3, 8.7, 9.5, 2.3, 5.8 };
	int size = sizeof(arrayDouble) / sizeof(arrayDouble[0]);

	printf("배열 : ");
	printArray(arrayDouble, size);

	ArrayRe(arrayDouble, size);

	printf("역순 : ");
	printArray(arrayDouble, size);
}

// 배열을 출력하는 함수
void printArray(double arrayDouble[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1lf ", arrayDouble[i]); /*
											배열 속 값들은 모두 소수점 첫째자리에서 끝나는 값이므로
											%.1lf로 정확히 출력할 수 있도록 했다.
											*/
	}

	printf("\n");
}

// 배열을 역순으로 바꾸는 함수
void ArrayRe(double arrayDouble[], int size)
{
	/*
		size / 2인 이유는 한번 서로 자리를 교체하면
		교체했던 원소를 다시 원래 위치로 돌아가게 한다.
		그래서 절반까지만 반복 수행을 하는 것이다.

		포인터를 이용한 다른 방법으로는,
		배열 선언 후, 다른 포인터 변수를 선언한다.
		double *p = &arrayDouble[9];

		그리고 역순으로 출력할 때, double rev[size]; 새로 선언,
		그 배열에다 p를 저장하는 반복문
		for(int a = 0; a < size; a++, p--)
		{
			rev[i] = *p;
		}
		그리고 rev 배열을 차례대로 출력하면 된다.
	*/

	for (int a = 0; a < (size / 2); a++)
	{
		double base = arrayDouble[a];

		/*
			a가 0일때, size - 1 - a는 10 - 1 - 0 = 9이므로
			0과 9가 짝이 된다. 즉 원래 순서를 base에 임시로 저장한 뒤에
			0번째(첫번째) 원소와 9번째(10번째) 원소의 위치를 바꾸는 것이다.
		*/
		arrayDouble[a] = arrayDouble[size - 1 - a];
		arrayDouble[size - 1 - a] = base;
	}
}
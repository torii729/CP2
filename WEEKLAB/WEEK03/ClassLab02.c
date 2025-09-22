/*
	2025.09.17~ 강의 실습
	chap08 함수와 포인터
*/
#include <stdio.h>

int test_function_pointer();
double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);

int main()
{
	test_function_pointer();
	return 0;
}

/*
	반환 타입이나 매개 변수가 동일한 여러 함수가 있다.
	함수 또한 포인터로 다룰 수 있다.
*/

int test_function_pointer()
{
	// pfunc은 함수의 포인터다. 매개변수는 double, double을 반환한다. NULL로 초기화한다.
	double (*pfunc)(double a, double b) = NULL;
	double result = 0.0;

	pfunc = add;
	
	add(3.0, 4.0);
	result = (*pfunc) (3, 4); // pfunc이 가리키는 함수의 값!

	printf("(*pfunc)(3, 4)의 결과는 : %.1f\n", (*pfunc) (3, 4));
	
	pfunc = mul;
	printf("(*pfunc)(3, 4)의 결과는 : %.1f\n", (*pfunc) (3, 4));
}

double add(double a, double b)
{
	return a + b;
}

double sub(double a, double b)
{
	return a - b;
}

double mul(double a, double b)
{
	return a * b;
}
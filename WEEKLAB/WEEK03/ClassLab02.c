/*
	2025.09.17~
	chap08
	�Լ��� ������ ���� �ǽ�
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
	��ȯ Ÿ���̳� �Ű� ������ ������ ���� �Լ��� �ִ�.
	�Լ� ���� �����ͷ� �ٷ� �� �ִ�.
*/

int test_function_pointer()
{
	// pfunc�� �Լ��� �����ʹ�. �Ű������� double, double�� ��ȯ�Ѵ�. NULL�� �ʱ�ȭ�Ѵ�.
	double (*pfunc)(double a, double b) = NULL;
	double result = 0.0;

	pfunc = add;
	
	add(3.0, 4.0);
	result = (*pfunc) (3, 4); // pfunc�� ����Ű�� �Լ��� ��!

	printf("(*pfunc)(3, 4)�� ����� : %.1f\n", (*pfunc) (3, 4));
	
	pfunc = mul;
	printf("(*pfunc)(3, 4)�� ����� : %.1f\n", (*pfunc) (3, 4));
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
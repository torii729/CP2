/*
	PPT 문제 풀이

	예제 8-14 의 데이터 타입들을 int 에서 double 로 변형해서 코딩하고 테스트하기
*/

#include <stdio.h>

void get_sum_product(double x, double y, double* sum, double* product);

int main(void)
{
    double result1, result2;

    get_sum_product(10.5, 20.2, &result1, &result2);

    printf("sum = %.2f, product = %.2f\n", result1, result2);

    return 0;
}

void get_sum_product(double x, double y, double* sum, double* product)
{
    if (sum == NULL || product == NULL)
    {
        // NULL 포인터 체크
        return;
    }

    *sum = x + y;
    *product = x * y;
}
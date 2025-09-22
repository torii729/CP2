/*
	PPT 문제 풀이

	예제 8-13 의 데이터 타입들을 int 에서 double 로 변형해서 코딩하고 테스트하기
	void * swap(double * a, double * b)
	단, 포인터가 NULL인지 테스트할 것
	반환 값: a 또는 b 포인터가 NULL이면 NULL, 그렇지 않으면 a 값을 반환
*/

#include <stdio.h>

void* swap(double* a, double* b);

int main(void)
{
    double x = 3.3, y = 7.7;

    printf("전 : x = %.1f, y = %.1f\n", x, y);

    // 정상 교환
    if (swap(&x, &y) == NULL)
        printf("스왑 실패\n");
    else
        printf("후 :  x = %.1f, y = %.1f\n", x, y);

    // NULL 테스트
    if (swap(NULL, &y) == NULL)
        printf("스왑 실패\n");

    return 0;
}

void* swap(double* a, double* b)
{
    if (a == NULL || b == NULL)  // NULL 포인터 체크
        return NULL;

    double temp = *a;
    *a = *b;
    *b = temp;

    return a;   // 문제 조건: a 반환
}
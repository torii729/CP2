/*
   Chap08 Programming Assignment 풀이

   파일명 : Assign01.c
   문제 : 1. 크기가 3인 double형 배열의 모든 원소의 주소를 출력하는 프로그램. 주소 구하기 연산자?를 사용하지 마시오.

   작성일자 : 2025.09.22
*/

#include <stdio.h>

void test(void);

int main(void)
{
    test();
    return 0;
}

// double[3]의 각 원소 주소를 찍는다
void test(void)
{
    double x[3] = { 1.1, 2.2, 3.3 };

    // 주소 찍을 때는 %p 씀
    // %p를 쓸 때는 (void*)로 바꿔서 넣는다. 
    // 배열 이름 x는 배열의 첫 번째 칸 주소처럼 행동한다. x+1은 두 번째 칸 주소임. x+2는 세 번째 칸 주소...
    printf("x[0] 주소: %p\n", (void*)(x + 0));
    printf("x[1] 주소: %p\n", (void*)(x + 1));
    printf("x[2] 주소: %p\n", (void*)(x + 2));

    // 주소가 일정 간격으로 커짐. double은 크기가 크기 때문에 간격 또한 크다고 할 수 있다.
}

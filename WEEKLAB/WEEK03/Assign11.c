/*
   Chap08 Programming Assignment 풀이

   파일명 : Assign11.c
   문제 : 11. 직사각형의 넓이와 둘레를 구하는 get_rect_info 함수를 작성. 직사각형의 가로, 세로의 길이를 입력받은 다음 get_rect_info함수를 이용해서 
		직사각형의 넓이와 둘레를 구해서 출력하는 프로그램 작성.
   
   작성일자 : 2025.09.22
*/

#include <stdio.h>

void test(void);
void get_rect_info(int w, int h, int* area, int* peri);

int main(void)
{
    test();
    return 0;
}

// w, h를 받아서 넓이랑 둘레를 바깥 변수에 적어줌
void get_rect_info(int w, int h, int* area, int* peri)
{
    // 넓이 = 가로 * 세로
    *area = w * h;

    // 둘레 = (가로 + 세로) * 2
    *peri = 2 * (w + h);
}

// 테스트 실행
void test(void)
{
    int w = 0;
    int h = 0;
    int area = 0;
    int peri = 0;

    printf("가로? ");
    if (scanf_s("%d", &w) != 1)
    {
        printf("입력 오류\n");
        return;
    }

    printf("세로? ");
    if (scanf_s("%d", &h) != 1)
    {
        printf("입력 오류\n");
        return;
    }

    get_rect_info(w, h, &area, &peri);

    printf("넓이: %d, 둘레: %d\n", area, peri);
}

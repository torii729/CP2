/*
    PPT 문제 풀이

	1. 앞에서 구현한 selectionSortInt 함수를 실수에 적용할 수 있도록
	selecttionSortFloat함수로 구현하시오.

	2. 표준 라이브러리의 qsort 함수를 이용하여 실수 배열에 대한 정렬을 하도록 하시오.

	3. 앞에서 구현한 selectionSortInt 함수를 qsort 처럼 임의의 배열에 대해 정렬할 수
	있도록 변경하시오.

	4. 표준 라이브러리의 qsort 함수를 이용하여 연락처 구조체 타입에 대한 정렬 하는
	예시코드를 작성하시오.

	작성일자 : 2025.09.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int selecttionSortFloat(float R[], int n);
int qsortfloat(const void* a, const void* b);
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*));
int contactUp(const void* a, const void* b);

// 메인
int main(void)
{
    return 0;
}

// 1번. selecttionSortFloat
int selecttionSortFloat(float R[], int n)
{
    int i = 0;
    int j = 0;
    int m = 0;

    for (i = 0; i < n - 1; i++)
    {
        m = i;

        for (j = i + 1; j < n; j++)
        {
            if (R[j] < R[m])
            {
                m = j;
            }
        }
        if (m != i)
        {
            float t = R[i];
            R[i] = R[m];
            R[m] = t;
        }
    }
    return 0;
}

// 2번. qsort로 float 정렬
// qsortfloat는 qsort에서 사용할 비교 함수로, 두 float 값을 오름차순 정렬 기준으로 비교한다.
// 매개변수 a, b는 void*로 들어오니까 float*로 형변환 후 값 비교에 사용한다.
// 반환값은 음수(앞이 더 작을때), 0(같을때), 양수(앞이 더 클때)으로 qsort가 정렬 순서를 결정한다.
int qsortfloat(const void* a, const void* b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;

    return 0;
}


// 3번. selectionSortInt를 임의의 배열에 대해 정렬
// selectionSortInt: 임의의 배열을 선택 정렬(오름차순)한다.
// cmp가 있으면 그 비교 규칙을 쓰고, 없으면 int로 간주해 비교한다.
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*))
{
    char* a = (char*)base;

    for (int i = 0; i < n - 1; i++)
    {
        int m = i;

        for (int j = i + 1; j < n; j++)
        {
            void* pj = a + j * sz; // j번째 원소의 주소
            void* pm = a + m * sz; // 현재 최소 원소의 주소

            int c = 0; // 비교 결과(음수/0/양수)를 담는 변수

            if (cmp)
            {
                c = cmp(pj, pm); // 사용자 비교 함수 결과 그대로 사용(음수/0/양수 계약 유지)
            }
            else
            {
                // 비교기가 없을 때는 int로 간주해 직접 비교한다.
                // if-else로 -1/0/1을 명시적으로 만드는 이유는
                // 음수, 0, 양수 형태로 결과를 통일하면 qsort처럼 될 것 같아서...
                int x = *(int*)pj;
                int y = *(int*)pm;

                if (x < y)
                {
                    c = -1;
                }
                else if (x > y)
                {
                    c = 1;
                }
                else
                {
                    c = 0;
                }
            }

            if (c < 0) m = j; // pj가 더 작으면 최소 인덱스 갱신
        }

        if (m != i)
        {
            // 바이트 단위 스왑하기. 임의 타입에도 동작한다
            for (int k = 0; k < sz; k++)
            {
                char* p = a + i * sz + k;
                char* q = a + m * sz + k;
                char t = *p; *p = *q; *q = t;
            }
        }
    }
    return 0;
}

// 4번. qsort로 Contact 정렬
// qsort에서 사용할 비교 함수로, 두 Contact 구조체의 name을 비교한다.  
// void* 포인터를 Contact*로 형변환, 구조체 멤버에 접근한다.  
// strcmp로 문자열 사전순을 판단하고, 반환값에 따라 오름차순 정렬된다.  

int contactUp(const void* a, const void* b)
{
    const Contact* x = (const Contact*)a;
    const Contact* y = (const Contact*)b;

    return strcmp(x->name, y->name);
}
/*
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
int qsortfloat(const void* a, const void* b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;

    return 0;
}

// selectionSortInt를 임의의 배열에 대해 정렬
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*))
{
    char* a = (char*)base;
    int i, j, m, k;

    for (i = 0; i < n - 1; i++)
    {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            void* pj = a + j * sz;
            void* pm = a + m * sz;
            int c;
            if (cmp)
            {
                c = cmp(pj, pm);
            }
            else
            {
                int x = *(int*)pj;
                int y = *(int*)pm;
                if (x < y) c = -1;
                else if (x > y) c = 1;
                else c = 0;
            }
            if (c < 0) m = j;
        }
        if (m != i)
        {
            for (k = 0; k < sz; k++)
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








// 아니 이게 뭐임?
int contactUp(const void* a, const void* b)
{
    const Contact* x = (const Contact*)a;
    const Contact* y = (const Contact*)b;
    return strcmp(x->name, y->name);
}

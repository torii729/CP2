/*
	1. �տ��� ������ selectionSortInt �Լ��� �Ǽ��� ������ �� �ֵ���
	selecttionSortFloat�Լ��� �����Ͻÿ�.

	2. ǥ�� ���̺귯���� qsort �Լ��� �̿��Ͽ� �Ǽ� �迭�� ���� ������ �ϵ��� �Ͻÿ�.

	3. �տ��� ������ selectionSortInt �Լ��� qsort ó�� ������ �迭�� ���� ������ ��
	�ֵ��� �����Ͻÿ�.

	4. ǥ�� ���̺귯���� qsort �Լ��� �̿��Ͽ� ����ó ����ü Ÿ�Կ� ���� ���� �ϴ�
	�����ڵ带 �ۼ��Ͻÿ�.

	�ۼ����� : 2025.09.15
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

int selecttionSortFloat(float R[], int n);
int qsortfloat(const void* a, const void* b);
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*));
int contactUp(const void* a, const void* b);

// ����
int main(void)
{
    return 0;
}

// 1��. selecttionSortFloat
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

// 2��. qsort�� float ����
int qsortfloat(const void* a, const void* b)
{
    float x = *(const float*)a;
    float y = *(const float*)b;

    return 0;
}

// selectionSortInt�� ������ �迭�� ���� ����
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

// 4��. qsort�� Contact ����








// �ƴ� �̰� ����?
int contactUp(const void* a, const void* b)
{
    const Contact* x = (const Contact*)a;
    const Contact* y = (const Contact*)b;
    return strcmp(x->name, y->name);
}

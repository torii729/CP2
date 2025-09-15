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

/* ---------------- 1) selecttionSortFloat ---------------- */
int selecttionSortFloat(float R[], int n) {
    if (n <= 0) return -1;
    int i, j, m;
    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++) {
            if (R[j] < R[m]) m = j;
        }
        if (m != i) {
            float t = R[i]; R[i] = R[m]; R[m] = t;
        }
    }
    return 0;
}

/* ---------------- 2) qsort�� float ���� ---------------- */
/* qsort ���Լ��� ǥ�� �ñ״�ó �ʿ� (const void*) */
int cmpFloatAsc(const void* a, const void* b) {
    float x = *(const float*)a;
    float y = *(const float*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

/* ---------------- 3) selectionSortInt�� ���ʸ����� ���� ----------------
   - �Լ� "����"�� �����ϰ�, �����Լ� �߰� ����
   - cmp == NULL �̸� �⺻ int ��
*/
int selectionSortInt(void* base, int n, int sz, int (*cmp)(void*, void*)) {
    if (base == 0 || n <= 0 || sz <= 0) return -1;

    char* a = (char*)base;
    int i, j, m, k;

    for (i = 0; i < n - 1; i++) {
        m = i;
        for (j = i + 1; j < n; j++) {
            void* pj = a + j * sz;
            void* pm = a + m * sz;
            int c;
            if (cmp) {
                c = cmp(pj, pm);
            }
            else {
                int x = *(int*)pj;
                int y = *(int*)pm;
                if (x < y) c = -1;
                else if (x > y) c = 1;
                else c = 0;
            }
            if (c < 0) m = j;
        }
        if (m != i) {
            for (k = 0; k < sz; k++) {
                char* p = a + i * sz + k;
                char* q = a + m * sz + k;
                char t = *p; *p = *q; *q = t;
            }
        }
    }
    return 0;
}

/* ---------------- 4) qsort�� Contact ���� ���� ---------------- */
typedef struct _contact {
    char name[64];
    char phone1[24];
} Contact;

/* �̸� ���� �������� */
int cmpContactByName(const void* a, const void* b) {
    const Contact* x = (const Contact*)a;
    const Contact* y = (const Contact*)b;
    return strcmp(x->name, y->name);
}

/* ====== ��� & �׽�Ʈ (main�� ȣ�⸸) ====== */
void pF(float A[], int n) { int i; for (i = 0; i < n; i++) printf("%.2f ", A[i]); printf("\n"); }
void pI(int A[], int n) { int i; for (i = 0; i < n; i++) printf("%d ", A[i]);   printf("\n"); }
void pC(Contact A[], int n) { int i; for (i = 0; i < n; i++) printf("[%d] %s / %s\n", i, A[i].name, A[i].phone1); printf("\n"); }

/* 1) selecttionSortFloat �׽�Ʈ */
int test_selecttionSortFloat(void) {
    float A[] = { 3.1f, -2.0f, 1.5f, 0.0f, 1.49f };
    int n = (int)(sizeof(A) / sizeof(A[0]));
    printf("[1] float �������� ��: "); pF(A, n);
    if (selecttionSortFloat(A, n) != 0) return -1;
    printf("[1] float �������� ��: "); pF(A, n);
    return 0;
}

/* 2) qsort float �׽�Ʈ */
int test_qsortFloat(void) {
    float B[] = { 5.5f, 5.4f, 9.1f, -1.0f, 2.2f };
    int n = (int)(sizeof(B) / sizeof(B[0]));
    printf("[2] qsort(float) ��: "); pF(B, n);
    qsort(B, (size_t)n, sizeof(float), cmpFloatAsc);
    printf("[2] qsort(float) ��: "); pF(B, n);
    return 0;
}

/* 3) ���ʸ� selectionSortInt �׽�Ʈ (int �迭) */
int cmpIntAsc_noConst(void* a, void* b) {
    int x = *(int*)a, y = *(int*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
int test_selectionSortInt(void) {
    int C[] = { 42, 0, -7, 13, 9, 9 };
    int n = (int)(sizeof(C) / sizeof(C[0]));
    printf("[3] generic int ��: "); pI(C, n);
    if (selectionSortInt(C, n, (int)sizeof(int), cmpIntAsc_noConst) != 0) return -1;
    printf("[3] generic int ��: "); pI(C, n);
    return 0;
}

/* 4) qsort Contact �׽�Ʈ */
int test_qsortContact(void) {
    Contact P[] = {
        {"ȫ�浿", "010-2222-3333"},
        {"Alice", "010-9999-8888"},
        {"�̿���", "010-1111-2222"},
        {"Bob",   "010-1234-5678"}
    };
    int n = (int)(sizeof(P) / sizeof(P[0]));
    printf("[4] qsort(Contact, �̸�) ��:\n"); pC(P, n);
    qsort(P, (size_t)n, sizeof(Contact), cmpContactByName);
    printf("[4] qsort(Contact, �̸�) ��:\n"); pC(P, n);
    return 0;
}

/* -------- main: �׽�Ʈ ȣ�⸸ -------- */
int main(void) {
    test_selecttionSortFloat();
    test_qsortFloat();
    test_selectionSortInt();
    test_qsortContact();
    return 0;
}

/*
   Chap08 Programming Assignment Ǯ��

   ���ϸ� : Assign11.c
   ���� : 11. ���簢���� ���̿� �ѷ��� ���ϴ� get_rect_info �Լ��� �ۼ�. ���簢���� ����, ������ ���̸� �Է¹��� ���� get_rect_info�Լ��� �̿��ؼ� 
		���簢���� ���̿� �ѷ��� ���ؼ� ����ϴ� ���α׷� �ۼ�.
   
   �ۼ����� : 2025.09.22
*/

#include <stdio.h>

void test(void);
void get_rect_info(int w, int h, int* area, int* peri);

int main(void)
{
    test();
    return 0;
}

// w, h�� �޾Ƽ� ���̶� �ѷ��� �ٱ� ������ ������
void get_rect_info(int w, int h, int* area, int* peri)
{
    // ���� = ���� * ����
    *area = w * h;

    // �ѷ� = (���� + ����) * 2
    *peri = 2 * (w + h);
}

// �׽�Ʈ ����
void test(void)
{
    int w = 0;
    int h = 0;
    int area = 0;
    int peri = 0;

    printf("����? ");
    if (scanf_s("%d", &w) != 1)
    {
        printf("�Է� ����\n");
        return;
    }

    printf("����? ");
    if (scanf_s("%d", &h) != 1)
    {
        printf("�Է� ����\n");
        return;
    }

    get_rect_info(w, h, &area, &peri);

    printf("����: %d, �ѷ�: %d\n", area, peri);
}

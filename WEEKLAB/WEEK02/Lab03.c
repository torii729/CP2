/*
    PPT 문제 풀이

	배열 범위 중 최소값 찾는 함수 :
	int findMinInt(int R[], int from, int to) : from부터 to까지 최소값을 갖는 인덱스 하나를 반환

	배열의 두 원소를 교환하기 :
	void swapInt(int R[], int aindex, int bindex)

	두 함수를 구현하고, 이를 이용한 선택정렬 함수를 구현
	Int selectionSortInt(int R[], int length) : 정상 0, 실패 0이 아닌 수

	테스트 코드
	잘 동작하는지 시험하는 함수를 작성하고 main에서 호출
	Int test_selectionSortInt(void) : 성공 0, 실패 0이 아닌 수
	임의의 정수 배열을 선언한 후 정렬하고, 원래 배열과 정렬된 결과를 출력
	
	작성일자 : 2025.09.15
*/

#include <stdio.h>

int findMinInt(int R[], int from, int to);
void swapInt(int R[], int aindex, int bindex);
int test_selectionSortInt();
int selectionSortInt(int R[], int length);


int main()
{
    test_selectionSortInt();
    return 0;
}

// 특정 구간에서 최소값의 인덱스 반환
int findMinInt(int R[], int from, int to)
{
    int min_Index = from;
    int i = 0;

    for (i = from + 1; i <= to; i++) 
    {
        if (R[i] < R[min_Index]) 
        {
            min_Index = i;
        }
    }
    return min_Index;
}

// 배열의 두 원소 교환하기(껍데기 temp 하나 만들어서)
void swapInt(int R[], int aindex, int bindex)
{
    int temp = R[aindex];
    R[aindex] = R[bindex];
    R[bindex] = temp;
}

// 선택 정렬 함수
int selectionSortInt(int R[], int length)
{
    for (int i = 0; i < length - 1; i++) 
    {
        int minIndex = findMinInt(R, i, length - 1);

        if (minIndex != i)
        {
            swapInt(R, i, minIndex);
        }
    }
    return 0;
}

// 선택 정렬 테스트 함수
int test_selectionSortInt()
{
    int arr[8] = { 64, 25, 12, 22, 11, 90, 55, 3 };
    int length = 8;

    printf("원래 배열 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int result = selectionSortInt(arr, length);

    printf("정렬된 배열 : ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


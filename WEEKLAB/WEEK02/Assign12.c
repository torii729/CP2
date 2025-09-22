/*
	Chap07 Programming Assignment 풀이

	파일명 : Assign12.c
	문제 : 12. 기차표 예매 프로그램을 작성하려고 한다. 간단한 구현을 위해 좌석은 모두 10개라고 하자.
	예매할 좌석수를 입력받아 빈 자리를 할당한다. 예매할 때마다 각 좌석의 상태를 출력한다.
	O이면 예매 가능, X면 예매 불가를 의미한다. 더 이상 예매할 수 없으면 프로그램을 종료한다.

	작성일자 : 2025.09.16
*/

/*
	전체적인 흐름 이해
	1. 현재 좌석 상태 출력
	2. 남은 좌석 수 확인
	3. o인 좌석부터 가능하면 예약
	3-1. 남은 좌석 수보다 많은 좌석을 예약하려 할땐 예매가 불가능하므로 종료
	4. 좌석 상태 출력
	5. 1~4의 반복
*/

/*
	예매가 불가능할 때까지 계속 좌석 예매를 반복해야 하므로 while문이나 for문
	좌석이 모두 예약이 되면(모두 X인 경우) 종료 break문
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sit();
void sitPrint(int sitTrain[], int size);
void sitInput(int sitTrain[], int size);
void sitCheck(int sitTrain[], int size);

// 함수를 호출하고 프로그램을 정상적으로 종료하는 함수
int main()
{
	sit();
	return 0;
}

// 변수의 선언 및 초기화, 함수를 호출함으로써 예약 실시
void sit()
{
	int sitTrain[10] = { 0 };
	int size = sizeof(sitTrain) / sizeof(sitTrain[0]);

	sitInput(sitTrain, size);
}

// 현재 좌석을 출력하는 함수
void sitPrint(int sitTrain[], int size)
{
	printf("현재 좌석 : [ ");

	// 좌석이 현재 0이면 'O'을 출력하고, 현재 1이면 'X'를 출력한다.
	for (int i = 0; i < size; i++)
	{
		if (sitTrain[i] == 0)
		{
			printf("O ");
		}
		else
		{
			printf("X ");
		}
	}
	printf("]\n");
}

// 좌석 예약을 입력받는 함수
void sitInput(int sitTrain[], int size)
{
	int num = 0;

	while (1)
	{
		int sitReserved[10] = { 0 }; // 계산하기 편리하게 예약된 좌석을 세는 배열을 따로 선언.
		int reserved = 0; // 이미 예약된 좌석 수
		int remain = 0; // 남은 좌석 수

		// 함수 호출을 통해 현재 좌석을 출력한다.
		sitPrint(sitTrain, size);

		printf("예매할 좌석수? ");
		scanf("%d", &num);


		// 남은 좌석 수를 계산한다.
		for (int i = 0; i < size; i++)
		{
			if (sitTrain[i] == 0)
			{
				remain++;
			}
		}

		/*
			예약할 좌석 수가 남은 좌석 수보다 많으면,
			예약 좌석이 부족하다는 문장과 함께 프로그램 종료.
		*/
		if (remain < num)
		{
			printf("예약 좌석이 부족합니다.\n");
			break;
		}

		// 예약 가능한 좌석에 순서대로 예약.
		for (int i = 0; reserved < num && i < size; i++)
		{
			if (sitTrain[i] == 0)
			{
				sitTrain[i] = 1; // 좌석은 0 -> 1로 변경
				sitReserved[reserved] = i + 1; /*
													사용자에겐 좌석 번호를 1부터 보여주기 위함.
													예를 들어 예약하고 싶은 좌석 수가 5라면 이 배열은
													sitReserved[10] = { 1, 2, 3, 4, 5, 0, 0, 0, 0, 0 }이 된다.
												*/
				reserved++; // 이미 예약된 좌석 수를 하나씩 증가
			}
		}

		// 예약된 좌석 번호를 출력.
		for (int j = 0; j < reserved; j++)
		{
			printf("%d ", sitReserved[j]);
		}
		printf("번 좌석을 예매했습니다.");
	}

	sitCheck(sitTrain, size);

}

// 남은 좌석을 검사하는 함수
void sitCheck(int sitTrain[], int size)
{
	int all = 1; // 좌석이 이미 꽉 찼다는(1) 가정을 둔다.

	for (int i = 0; i < size; i++)
	{
		if (sitTrain[i] == 0)
		{
			all = 0; // 좌석 예약이 모두 비었으므로 0으로 바꾸고 종료한다.
			break;
		}

		if (all == 1)
		{
			printf("모든 좌석 예매 완료."); /*
												좌석이 모두 1일때 이 if문이 실행된다.
												이 문장을 출력하고 프로그램을 종료.
												*/
			break;
		}
	}
}

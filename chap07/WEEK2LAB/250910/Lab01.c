/*
	실수 배열에 대한 다음 두 함수를 구현하고
	printArrayFloat(float R[], int size)
	copyArrayFloat(float from[], float to[], int size)

	Test 함수를 작성하고 main에서 호출하여 실행해 보시오
	Int test_printArrayFloat()
	Int Test_copyArrayFloat()

	작성일자 : 2025.09.15
*/

#include <stdio.h>


int main()
{
    test_printArrayFloat();
    test_copyArrayFloat();
    return 0;
}

// 실수 배열 출력 함수
void printArrayFloat(float R[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", R[i]);
    }
    printf("\n");
}

// 실수 배열 복사 함수
void copyArrayFloat(float from[], float to[], int size) {
    for (int i = 0; i < size; i++) {
        to[i] = from[i];
    }
}

// 배열 출력 테스트 함수
int test_printArrayFloat() {
    float arr[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    printf("test_printArrayFloat 결과: ");
    printArrayFloat(arr, 5);
    return 0;   // 정상 종료
}

// 배열 복사 테스트 함수
int test_copyArrayFloat() {
    float src[5] = { 10.0, 20.0, 30.0, 40.0, 50.0 };
    float dst[5];
    copyArrayFloat(src, dst, 5);

    printf("원본 배열: ");
    printArrayFloat(src, 5);
    printf("복사된 배열: ");
    printArrayFloat(dst, 5);

    return 0;   // 정상 종료
}
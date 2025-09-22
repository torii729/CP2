/*
	PPT 문제 풀이

	void printArrayInt(const int* arr, int size)
		포인터 ++ 연산자를 이용하여 구현하고 테스트
		단 포인터가 NULL인지 확인할 것
	void printArrayInt2(const int arr[], int size)
		배열 인덱스를 이용하여 구현하고 테스트
	int copyArrayFloat(const float* from, float* to, int size)
		포인터 ++연산자를 이용하여 구현하고 테스트
		반환 : size
		단 포인터들이 NULL인지 확인할 것
*/

/*
    void printArrayInt(const int* arr, int size)
       - 포인터 ++ 연산자로 순회
       - arr가 NULL이거나 size <= 0이면 안내 출력 후 반환한다.

    void printArrayInt2(const int arr[], int size)
       - 배열 인덱스로 순회
       - arr가 NULL이거나 size <= 0이면 안내 출력 후 반환한다.

    int copyArrayFloat(const float* from, float* to, int size)
       - 포인터 ++ 연산자로 복사한다.
       - 포인터/size 검증
       - 성공 시 size 반환, 실패 시 0 반환한다.
*/

#include <stdio.h> // 표준 입출력 사용

// 기능 함수 선언부
void printArrayInt(const int* arr, int size); // 포인터 ++로 int 배열 출력함
void printArrayInt2(const int arr[], int size); // 인덱스로 int 배열 출력한다.
int  copyArrayFloat(const float* from, float* to, int size); // 포인터 ++로 float 배열 복사함. 성공하면 size 반환한다.

// 테스트 함수 선언부
void test_all(void); // 전체 동작 한 번에 검증할 것임

int main(void) // 메인은 호출만 함
{
    test_all(); // 테스트 실행한다.
    return 0; // 정상 종료함
}

// 포인터 ++로 int 배열 출력하는 함수
void printArrayInt(const int* arr, int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("printArrayInt 함수 배열 없음 또는 크기 0\n"); // 인자 검증함
        return;
    }

    const int* p = arr; // 원본 보호용 지역 포인터 둠
    for (int i = 0; i < size; i++, p++)
    {
        printf("%d ", *p); // p 전진시키며 역참조로 값 출력한다.
    }
    printf("\n"); // 줄바꿈 출력함
}

// 인덱스로 int 배열 출력하는 함수
void printArrayInt2(const int arr[], int size)
{
    if (arr == NULL || size <= 0)
    {
        printf("printArrayInt2 함수 배열 없음 또는 크기 0\n"); // 인자 검증
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]); // 인덱스로 값 접근해 출력함
    }
    printf("\n"); // 줄바꿈 한다.
}

// 포인터 ++로 float 배열 복사함
int copyArrayFloat(const float* from, float* to, int size)
{
    if (from == NULL || to == NULL || size <= 0)
    {
        return 0; // 인자 검증한다. 조건 불만족 시 실패로 처리함
    }

    const float* pf = from; // 읽기 포인터. const 선언함으로써 읽기 전용
    float* pt = to; // 쓰기 포인터
    for (int i = 0; i < size; i++, pf++, pt++)
    {
        *pt = *pf; // 원소 단위로 복사한다.
    }

    return size; // 성공 개수 반환함
}

// 전체 기능 테스트하는 함수
void test_all(void)
{
    int ai[5] = { 10, 20, 30, 40, 50 }; // 정수 배열 준비
    printf("printArrayInt 함수의 ptr++  : ");
    printArrayInt(ai, 5); // 포인터 ++ 출력 확인

    printf("printArrayInt2 함수의 index : ");
    printArrayInt2(ai, 5); // 인덱스 출력 확인


    float src[4] = { 1.1f, 2.2f, 3.3f, 4.4f }; // 복사 원본 준비
    float dst[4] = { 0.0f, 0.0f, 0.0f, 0.0f }; // 복사 목적지 초기화

    int copied = copyArrayFloat(src, dst, 4); // 복사 시도
    if (copied == 4)
    {
        printf("copyArrayFloat 함수 : %d, dst : ", copied); // 성공 메시지 출력

        const float* p = dst; // 결과 확인용 포인터
        for (int i = 0; i < 4; i++, p++)
        {
            printf("%.1f ", *p); // 포인터 ++로 결과 출력
        }
        printf("\n"); // 줄바꿈 출력
    }
    else
    {
        printf("copyArrayFloat 실패 : %d\n", copied); // 실패 메시지 출력
    }

    printf("printArrayInt(NULL, 3) 결과 : ");
    printArrayInt(NULL, 3); // NULL 인자 방어 동작 확인

    printf("printArrayInt2(NULL, 0) 결과 : ");
    printArrayInt2(NULL, 0); // NULL + size 0 동작 확인

    printf("copyArrayFloat(NULL, dst, 4)의 반환 : %d\n", copyArrayFloat(NULL, dst, 4)); // from NULL 처리 확인함
    printf("copyArrayFloat(src, NULL, 4)의 반환 :% d\n", copyArrayFloat(src, NULL, 4)); // to NULL 처리 확인함
    printf("copyArrayFloat(src, dst, 0)의 반환 : %d\n", copyArrayFloat(src, dst, 0)); // size 0 처리 확인함
}

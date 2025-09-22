/*
    2025.09.17~ 강의 실습
    chap08 포인터
*/
#include <stdio.h>

void menu();
void test_swap_double();
void* swapDouble(double* a, double* b);
int test_print_array();
void print_array_double(double arr[], int sz);
void printArrayDouble(double* arr, int sz);

int main()
{
    menu();
    return 0;
}

void menu()
{
    while (1)
    {
        int choice = 0;

        printf("1. 스왑\n2. 배열 출력\n3. 종료\n어떤 함수를 실행하겠습니까? : ");
        scanf_s("%d", &choice);

        if (choice == 1)
        {
            test_swap_double();
        }
        else if (choice == 2)
        {
            test_print_array();
        }
        else if (choice == 3)
        {
            printf("\n종료합니다.");
            break;
        }
        else
        {
            printf("\n다시 입력해주세요.");
        }
    }
}

void test_swap_double()
{
    double x = 3.3, y = 6.6;

    // 1. x, y를 온전히 넘김
    double* pre = (double*)swapDouble(&x, &y);
    if (pre == NULL)
    {
        printf("pre 변수 : null\n");
    }
    else
    {
        printf("결과 : a = %.1f, b = %.1f\n", x, y);
    }

    // 2. null을 보내면?
    pre = swapDouble((double*)NULL, &y); // NULL을 넘겼기 때문에 pre == NULL이 된다. 당연히 결과가 출력되지 않는다.
    if (pre == NULL)
    {
        printf("pre 변수가 현재 NULL입니다.\n\n");
    }
    else
    {
        printf("결과 : a = %.1f, b = %.1f\n\n", x, y);
    }
}

// 변수 값 서로 바꾸는 함수(스왑)
void* swapDouble(double* a, double* b) // 반환 타입이 포인터인 함수 선언
{
    // 입력 값이 정상인지 체크한다(NULL이 아니어야 한다)
    if (a == NULL || b == NULL)
    {
        return NULL; // NULL 포인터를 방지한다(아무 것도 없는 걸 가리키면 그것은 유효한 메모리 주소가 아니다)
    }

    // 스왑한다. 임의의 변수 temp에 a가 가리키는 값을 넣어 저장하는 식. 이때 a, b와 타입이 같아야 한다.
    double temp = *a;
    *a = *b;
    *b = temp;

    return a;
}

// 배열을 출력하는 함수, 문제 있으면 return 1, 문제 없으면 return 0.
int test_print_array()
{
    double arr[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int size = sizeof(arr) / sizeof(arr[0]); // 전체 / 첫번째 원소

    print_array_double(arr, size); // 배열 이름
    printArrayDouble(&arr[0], size); // 포인터(가리킨다), 배열의 첫번째 원소의 주소를 매개변수로서 보내야 한다.

    return 0;
}

/*
    기능 : 1차원 실수 배열을 입력 받아서 콘솔에 출력한다.
    함수명 : print_array_double(배열 사용), printArrayDouble(포인터 사용)
    입력 : double 타입 1차원 배열 주소
    출력 : 터미널에 배열의 내용을 예쁘게 출력한다.
    반환 : 없음
*/
void print_array_double(double arr[], int sz)
{
    printf("배열을 사용 : ");
    for (int i = 0; i < sz; i++)
    {
        printf("%.1f ", arr[i]);
    }
    printf("\n");
}

void printArrayDouble(double *arr, int sz)
{
    printf("포인터를 사용 : ");
    for (int i = 0; i < sz; i++, arr++)
    {
        printf("%.1f ", *arr);
    }
    printf("\n\n");
}


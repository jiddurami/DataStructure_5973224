#include <stdio.h>

// 사칙연산 함수 선언
int add(int a, int b);      // 덧셈 함수
int subtract(int a, int b); // 뺄셈 함수
int multiply(int a, int b); // 곱셈 함수
float divide(int a, int b); // 나눗셈 함수

int main() {
    int num1, num2;

    // 사용자로부터 두 개의 양의 정수 입력받기
    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf_s("%d", &num1);

    printf("두 번째 양의 정수를 입력하세요: ");
    scanf_s("%d", &num2);

    // 사칙연산 결과 출력
    printf("덧셈: %d\n", add(num1, num2));
    printf("뺄셈: %d\n", subtract(num1, num2));
    printf("곱셈: %d\n", multiply(num1, num2));
    printf("나눗셈: %.2f\n", divide(num1, num2));

    return 0;
}

// 덧셈 함수 정의(두 정수의 합을 반환)
int add(int a, int b) {
    return a + b;
}

// 뺄셈 함수 정의(첫 번째 정수에서 두 번째 정수를 뺀 값을 반환)
int subtract(int a, int b) {
    return a - b;
}

// 곱셈 함수 정의(두 정수를 곱을 반환)
int multiply(int a, int b) {
    return a * b;
}

// 나눗셈 함수 정의(첫 번째 정수를 두 번째 정수로 나눈 값을 반환)
float divide(int a, int b) {
    return a / (float)b; //형 변환(정확한 연산 위해서)
}
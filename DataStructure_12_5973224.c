/*
n=10일 때
fibonacci_rec(재귀적방법)
호출 횟수 : fibonacci_rec(10)은 177번 호출됨.
Fibonacci(11)=89이므로 2×89 - 1 = 177
호출 된 이유
함수가 자기 자신을 두 번씩 재귀 호출하여 동일한 부분 문제를 여러번 계산하기 때문.
결론 : n이 얼마느냐에 따라 기하급수적 증가

fibonacci_itr(순환적방법)
호출 횟수 : fibonacci_itr(10)은 1번 호출됨.
호출 된 이유
반복문을 사용하여 한 번의 함수 호출 내에서 순차적으로 계산하기 때문
결론 : 선형적으로 증가
*/


#include <stdio.h>
#include <stdlib.h>

// 순환적 방법
int fibonacci_itr(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int f1 = 0, f2 = 1, f3;
    for (int i = 2; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f2;
}

// 재귀적 방법
int fibonacci_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main(void) {
    int n, method;

    while (1) {
        printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료) : ");
        scanf_s("%d", &method);

        if (method == 0) {
            printf("프로그램이 종료되었습니다.\n");
            break;
        }

        printf("정수 N을 입력하세요 (종료하려면 0 입력) : ");
        scanf_s("%d", &n);

        int result;
        if (method == 1) {
            result = fibonacci_rec(n);
            printf("F(%d) = %d (재귀적 방법)\n", n, result);
        }
        else if (method == 2) {
            result = fibonacci_itr(n);
            printf("F(%d) = %d (순환적 방법)\n", n, result);
        }
        else {
            printf("다시입력\n");
        }
    }

    return 0;
}
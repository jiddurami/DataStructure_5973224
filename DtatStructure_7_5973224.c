#include <stdio.h>
#include <stdlib.h>

float add(float a, float b) { return a + b; }
float subtract(float a, float b) { return a - b; }
float multiply(float a, float b) { return a * b; }
float divide(float a, float b) { return a / b; }

float evaluate(const char* expression) {
    float nums[10];
    char ops[10];
    int numCount = 0, opCount = 0;

    // 수식에서 숫자와 연산자를 분리하여 저장 
    char* ptr = (char*)expression;
    while (*ptr) {
        if (*ptr >= '0' && *ptr <= '9') { // 숫자
            nums[numCount++] = strtof(ptr, &ptr);
        }
        else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') { // 연산자
            ops[opCount++] = *ptr;
            ptr++;
        }
        else {
            ptr++;
        }
    }

    // 곱셈과 나눗셈 처리
    for (int i = 0; i < opCount; i++) {
        if (ops[i] == '*' || ops[i] == '/') {
            float result = (ops[i] == '*') ? multiply(nums[i], nums[i + 1]) : divide(nums[i], nums[i + 1]);
            nums[i] = result;
            for (int j = i + 1; j < numCount - 1; j++) {
                nums[j] = nums[j + 1];
            }
            numCount--; // 숫자 개수 줄이기
            for (int j = i; j < opCount - 1; j++) {
                ops[j] = ops[j + 1];
            }
            opCount--; // 연산자 개수 줄이기
            i--; // 같은 위치에서 다시 검사
        }
    }

    // 덧셈과 뺄셈 처리
    float result = nums[0];
    for (int i = 0; i < opCount; i++) {
        result = (ops[i] == '+') ? add(result, nums[i + 1]) : subtract(result, nums[i + 1]);
    }
    return result;
}

int main() {
    char expression[100];

    printf("계산할 수식을 입력하세요 (예: 3 + 5 * 2 - 8 / 4): ");
    fgets(expression, sizeof(expression), stdin); // 한 줄 입력 받기

    float result = evaluate(expression);
    printf("결과: %.6f\n", result);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int* f = (int*)malloc(sizeof(int) * 4);
    int* s = (int*)malloc(sizeof(int) * 4);

    printf("첫 번째 2x2 행렬 입력 : \n");
    for (int i = 0; i < 4; i++) {
        scanf_s("%d", f + i);
    }

    printf("두 번째 2x2 행렬 입력 : \n");
    for (int i = 0; i < 4; i++) {
        scanf_s("%d", s + i);
    }

    printf("행렬 덧셈 결과 : \n");
    for (int i = 0; i < 4; i++) {
        int sum = *(f + i) + *(s + i);
        printf("%d ", sum);
    }

    free(f);
    free(s);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct student {
    char name[10];
    int num;
    int score;
} st;

int main() {
    int n;
    st* p = NULL;

    printf("몇 명의 학생 정보를 입력하시나요? ");
    scanf("%d", &n);

    p = (st*)malloc(sizeof(st) * n);

    for (int i = 0; i < n; i++) {
        printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", i + 1);
        scanf("%s %d %d", (p + i)->name, &(p + i)->num, &(p + i)->score);
    }

    int input_num;
    while (1) {
        printf("학번을 입력하세요(0이면 종료)? ");
        scanf("%d", &input_num);

        if (input_num == 0)
            break;

        int found = 0;
        for (int i = 0; i < n; i++) {
            if ((p + i)->num == input_num) {
                printf("학생 정보: %s %d %d\n", (p + i)->name, (p + i)->num, (p + i)->score);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("해당 학번의 학생이 없습니다.\n");
    }

    free(p);
    return 0;
}
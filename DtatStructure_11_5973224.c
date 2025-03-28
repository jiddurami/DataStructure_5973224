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

    printf("�� ���� �л� ������ �Է��Ͻó���? ");
    scanf("%d", &n);

    p = (st*)malloc(sizeof(st) * n);

    for (int i = 0; i < n; i++) {
        printf("[%d] �л��� ������ �Է��ϼ��� (�̸� �й� ����): ", i + 1);
        scanf("%s %d %d", (p + i)->name, &(p + i)->num, &(p + i)->score);
    }

    int input_num;
    while (1) {
        printf("�й��� �Է��ϼ���(0�̸� ����)? ");
        scanf("%d", &input_num);

        if (input_num == 0)
            break;

        int found = 0;
        for (int i = 0; i < n; i++) {
            if ((p + i)->num == input_num) {
                printf("�л� ����: %s %d %d\n", (p + i)->name, (p + i)->num, (p + i)->score);
                found = 1;
                break;
            }
        }

        if (!found)
            printf("�ش� �й��� �л��� �����ϴ�.\n");
    }

    free(p);
    return 0;
}
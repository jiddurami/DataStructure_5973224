#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[14];
} element;

void menu_list() {
    printf("===== ��ȭ��ȣ�� �޴� =====\n");
    printf("1. ����ó �߰�\n");
    printf("2. ����ó ����\n");
    printf("3. ����ó �˻�\n");
    printf("4. ��ü ����ó ���\n");
    printf("0. ����\n");
    printf("�޴��� �����ϼ��� : ");
}

void add(element* list, int* count) {
    element* p = list + *count;
    printf("�̸��� �Է��ϼ��� : ");
    scanf_s("%s", p->name, (unsigned)sizeof(p->name));
    printf("��ȭ��ȣ�� �Է��ϼ��� : ");
    scanf_s("%s", p->phone, (unsigned)sizeof(p->phone));
    printf("����ó�� �߰��Ǿ����ϴ�.\n");
    (*count)++;
}

void del(element* list, int* count) {
    char target[50];
    printf("������ �̸��� �Է��ϼ��� : ");
    scanf_s("%s", target, (unsigned)sizeof(target));
    for (int i = 0; i < *count; i++) {
        if (strcmp(list[i].name, target) == 0) {
            for (int j = i; j < *count - 1; j++) {
                list[j] = list[j + 1];
            }
            (*count)--;
            printf("�����Ǿ����ϴ�.\n");
            return;
        }
    }
    printf("'%s' ����ó�� ã�� �� XXX\n", target);
}

void insert(element* list, int count) {
    char target[50];
    printf("�˻��� �̸��� �Է��ϼ��� : ");
    scanf_s("%s", target, (unsigned)sizeof(target));
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, target) == 0) {
            printf("�̸� : %s, ��ȭ��ȣ : %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("'%s' ����óXXX.\n", target);
}

void print_all(element* list, int count) {
    printf("----- ��ü ����ó -----\n");
    if (count == 0) {
        printf("��ϵ� ����ó XXX\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("[%d] �̸� : %s, ��ȭ��ȣ : %s\n", i + 1, list[i].name, list[i].phone);
    }
}

int main() {
    element contacts[MAX_CONTACTS] = { 0 };
    int n, count = 0;

    while (1) {
        menu_list();
        if (scanf_s("%d", &n) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');  

        if (n == 1) {
            add(contacts, &count);
        }
        else if (n == 2) {
            del(contacts, &count);
        }
        else if (n == 3) {
            insert(contacts, count);
        }
        else if (n == 4) {
            print_all(contacts, count);
        }
        else if (n == 0) {
            printf("����");
            break;
        }
    }
    return 0;
}

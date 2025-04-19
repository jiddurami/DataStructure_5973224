#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

typedef struct {
    char name[50];
    char phone[14];
} element;

void menu_list() {
    printf("===== 전화번호부 메뉴 =====\n");
    printf("1. 연락처 추가\n");
    printf("2. 연락처 삭제\n");
    printf("3. 연락처 검색\n");
    printf("4. 전체 연락처 출력\n");
    printf("0. 종료\n");
    printf("메뉴를 선택하세요 : ");
}

void add(element* list, int* count) {
    element* p = list + *count;
    printf("이름을 입력하세요 : ");
    scanf_s("%s", p->name, (unsigned)sizeof(p->name));
    printf("전화번호를 입력하세요 : ");
    scanf_s("%s", p->phone, (unsigned)sizeof(p->phone));
    printf("연락처가 추가되었습니다.\n");
    (*count)++;
}

void del(element* list, int* count) {
    char target[50];
    printf("삭제할 이름을 입력하세요 : ");
    scanf_s("%s", target, (unsigned)sizeof(target));
    for (int i = 0; i < *count; i++) {
        if (strcmp(list[i].name, target) == 0) {
            for (int j = i; j < *count - 1; j++) {
                list[j] = list[j + 1];
            }
            (*count)--;
            printf("삭제되었습니다.\n");
            return;
        }
    }
    printf("'%s' 연락처를 찾을 수 XXX\n", target);
}

void insert(element* list, int count) {
    char target[50];
    printf("검색할 이름을 입력하세요 : ");
    scanf_s("%s", target, (unsigned)sizeof(target));
    for (int i = 0; i < count; i++) {
        if (strcmp(list[i].name, target) == 0) {
            printf("이름 : %s, 전화번호 : %s\n", list[i].name, list[i].phone);
            return;
        }
    }
    printf("'%s' 연락처XXX.\n", target);
}

void print_all(element* list, int count) {
    printf("----- 전체 연락처 -----\n");
    if (count == 0) {
        printf("등록된 연락처 XXX\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("[%d] 이름 : %s, 전화번호 : %s\n", i + 1, list[i].name, list[i].phone);
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
            printf("종료");
            break;
        }
    }
    return 0;
}

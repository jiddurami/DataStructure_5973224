#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef struct { int row, col, value; } elementType;
typedef struct { elementType* array; int size, last; } listType;

listType* createList(int size) {
    listType* l = malloc(sizeof(listType));
    l->array = malloc(sizeof(elementType) * size);
    l->size = size; l->last = -1;
    return l;
}

int compare(elementType a, elementType b) {
    return a.row != b.row ? a.row - b.row : a.col - b.col;
}

void orderedInsert(listType* l, elementType item) {
    if (l->last + 1 >= l->size) return;
    int i;
    for (i = 0; i <= l->last; i++) {
        int cmp = compare(l->array[i], item);
        if (cmp == 0) { l->array[i].value += item.value; return; }
        if (cmp > 0) break;
    }
    for (int j = l->last + 1; j > i; j--)
        l->array[j] = l->array[j - 1];
    l->array[i] = item; l->last++;
}

void printList(listType* l) {
    printf("List: size = %d, last = %d\nItems:\n", l->size, l->last);
    for (int i = 0; i <= l->last; i++)
        printf("    [%d] %d, %d, %d\n", i, l->array[i].row, l->array[i].col, l->array[i].value);
}

void freeList(listType* l) {
    free(l->array); free(l);
}

listType* input(const char* prompt) {
    listType* l = createList(MAX_SIZE);
    int row, col, value;
    printf("%s\n", prompt);
    while (scanf_s("%d", &row) == 1 && row != -1) {
        scanf_s("%d%d", &col, &value);
        elementType item = { row, col, value };
        orderedInsert(l, item);
    }
    return l;
}

listType* addMatrices(listType* A, listType* B) {
    listType* res = createList(MAX_SIZE);
    int i = 0, j = 0;
    while (i <= A->last && j <= B->last) {
        int cmp = compare(A->array[i], B->array[j]);
        if (cmp < 0) { orderedInsert(res, A->array[i]); i++; }
        else if (cmp == 0) {
            int sum = A->array[i].value + B->array[j].value;
            if (sum) { elementType item = { A->array[i].row, A->array[i].col, sum }; orderedInsert(res, item); }
            i++; j++;
        }
        else { orderedInsert(res, B->array[j]); j++; }
    }
    while (i <= A->last) { orderedInsert(res, A->array[i]); i++; }
    while (j <= B->last) { orderedInsert(res, B->array[j]); j++; }
    return res;
}

int main() {
    listType* A = input("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)");
    listType* B = input("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)");
    listType* result = addMatrices(A, B);
    printf("두 행렬의 합\n");
    printList(result);
    freeList(A); freeList(B); freeList(result);
    return 0;
}

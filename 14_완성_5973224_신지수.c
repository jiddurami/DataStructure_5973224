#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int expo;   // 차수
    int coef;   // 지수 
} elementType;


typedef struct {
    elementType* array;
    int size;
    int last;
    int move;
} listType;


listType* createList(int size) {
    listType* lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
}


int compare_item(elementType item1, elementType item2) {
    return item1.expo - item2.expo;
}


int ordered_insertItem(listType* list, elementType item) {
    int i, j;

    for (i = 0; i <= list->last; i++) {
        int cmp = compare_item(list->array[i], item);
        if (cmp == 0) {
            list->array[i].coef += item.coef;
            if (list->array[i].coef == 0) {
                for (j = i; j < list->last; j++) {
                    list->array[j] = list->array[j + 1];
                    list->move++;
                }
                list->last--;
            }
            return 1;
        }
        if (cmp > 0) {
            break;
        }
    }

    for (j = list->last + 1; j > i; j--) {
        list->array[j] = list->array[j - 1];
        list->move++;
    }
    list->array[i] = item;
    list->last++;
    return 1;
}

void printList(listType* list) {
    printf("List: size=%d, last=%d, move=%d\n", list->size, list->last, list->move);
    printf("Items: P(x) = ");
    if (list->last < 0) {
        printf("0");
    }
    else {
        int printed = 0;

        for (int i = list->last; i >= 0; i--) {
            elementType term = list->array[i];

            if (printed && term.coef > 0)
                printf("+");
            if (term.expo == 0)
                printf("%d", term.coef);
            else if (term.expo == 1)
                printf("%dx", term.coef);
            else
                printf("%dx^%d", term.coef, term.expo);
            printed = 1;
        }
    }
    printf("\n");
}

listType* parsePolynomial(char* input) {

    listType* poly = createList(20);
    char* ptr = input;

    while (*ptr != '\0') {
        int sign = 1;

        if (*ptr == '+') {
            sign = 1;
            ptr++;
        }
        else if (*ptr == '-') {
            sign = -1;
            ptr++;
        }


        int coef = 0;
        if (isdigit(*ptr)) {
            coef = strtol(ptr, &ptr, 10);
        }
        else {

            coef = 1;
        }
        coef *= sign;

        int expo = 0;

        if (*ptr == 'x' || *ptr == 'X') {
            ptr++;
            if (*ptr == '^') {
                ptr++;
                expo = strtol(ptr, &ptr, 10);
            }
            else {
                expo = 1;
            }
        }
        else {
            expo = 0;
        }
        elementType term;
        term.coef = coef;
        term.expo = expo;
        ordered_insertItem(poly, term);
    }

    return poly;
}


listType* multiplyPolynomials(listType* poly1, listType* poly2) {
    listType* result = createList(6);

    for (int i = 0; i <= poly1->last; i++) {
        for (int j = 0; j <= poly2->last; j++) {
            elementType term;
            term.expo = poly1->array[i].expo + poly2->array[j].expo;
            term.coef = poly1->array[i].coef * poly2->array[j].coef;
            ordered_insertItem(result, term);
        }
    }
    return result;
}

int main() {
    char input1[100], input2[100];

    printf("첫 번째 다항식을 입력하세요 ( 예: 3x^2+4x+1):\n");
    fgets(input1, sizeof(input1), stdin);
    input1[strcspn(input1, "\n")] = '\0';

    printf("두 번째 다항식을 입력하세요 ( 예: 2x^2+5x+3):\n");
    fgets(input2, sizeof(input2), stdin);
    input2[strcspn(input2, "\n")] = '\0';

    listType* poly1 = parsePolynomial(input1);
    listType* poly2 = parsePolynomial(input2);

    listType* result = multiplyPolynomials(poly1, poly2);

    printf("\n[곱셈 결과]\n");
    printList(result);

    free(poly1->array);
    free(poly1);
    free(poly2->array);
    free(poly2);
    free(result->array);
    free(result);

    return 0;
}

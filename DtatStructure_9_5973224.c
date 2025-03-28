/*

의사코드
BEGIN
    // 1. 정수의 개수 입력
    PRINT "정수의 개수를 입력하세요 : "
    READ num

    // 2. num 크기의 배열 N 동적 할당
    ALLOCATE array N with size num

    // 3. num개의 정수를 배열에 입력
    PRINT "5개의 정수를 입력하세요 : "
    FOR i FROM 0 TO num - 1 DO
        READ N[i]
    END FOR

    // 4. 버블 정렬을 사용한 오름차순 정렬
    FOR i FROM 0 TO num - 1 DO
        // 각 패스마다 마지막 i개의 요소는 이미 정렬됨
        FOR j FROM 1 TO (num - i - 1) DO
            IF N[j - 1] > N[j] THEN
                // 인접한 두 요소를 교환(swap)
                temp ← N[j - 1]
                N[j - 1] ← N[j]
                N[j] ← temp
            END IF
        END FOR
    END FOR

    // 5. 정렬된 배열 출력
    PRINT "오름차순으로 정렬된 정수들 : "
    FOR i FROM 0 TO num - 1 DO
        PRINT N[i] + " "
    END FOR

END
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int num, temp;

	printf("정수의 개수를 입력하세요 : ");
	scanf_s("%d", &num);

	int* N = (int*)malloc(sizeof(int) * (num));
	
	printf("5개의 정수를 입력하세요 : \n");
	for (int i = 0; i < num; i++) {
		scanf_s("%d", &N[i]);
		}

	for (int i=0; i<num; i++){
		for (int j = 1; j < num-i; j++) {
			if (N[j-1] > N[j])
			{
				temp = N[j-1];
				N[j-1] = N[j];
				N[j] = temp;
			}
		}

	}

	printf("오름차순으로 정렬된 정수들 : \n");
	for (int i = 0; i < num; i++) {
		printf("%d ", N[i]);
	}

	return 0;
}
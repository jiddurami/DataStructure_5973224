/*

의사코드
BEGIN
    // 2x2 행렬 3개를 선언 (첫 번째 행렬 f, 두 번째 행렬 s, 결과 행렬 sum 초기값 0)
    DECLARE 2x2 integer array f
    DECLARE 2x2 integer array s
    DECLARE 2x2 integer array sum, INITIALIZED TO 0

    // 첫 번째 행렬 입력 받기
    PRINT "첫 번째 2x2 행렬 입력 :"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            READ integer INTO f[i][j]
        END FOR
    END FOR

    // 두 번째 행렬 입력 받기
    PRINT "두 번째 2x2 행렬 입력 :"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            READ integer INTO s[i][j]
        END FOR
    END FOR

    // 행렬 덧셈 연산 수행 및 결과 출력
    PRINT "행렬 덧셈 결과 :"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            SET sum[i][j] = f[i][j] + s[i][j]
            PRINT sum[i][j] + " "   // 결과 출력 (한 행의 요소들을 공백으로 구분)
        END FOR
        PRINT newline             // 각 행이 끝난 후 줄바꿈
    END FOR
END
*/

#include <stdio.h>

int main() {

	int f[2][2], s[2][2], sum[2][2] = { 0 };

	printf("첫 번째 2x2 행렬 입력 : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &f[i][j]);
		}
	}

	printf("두 번째 2x2 행렬 입력 : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &s[i][j]);
		}
	}

	printf("행렬 덧셈 결과 : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sum[i][j] = f[i][j] + s[i][j];
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
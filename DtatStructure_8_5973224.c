/*

�ǻ��ڵ�
BEGIN
    // 2x2 ��� 3���� ���� (ù ��° ��� f, �� ��° ��� s, ��� ��� sum �ʱⰪ 0)
    DECLARE 2x2 integer array f
    DECLARE 2x2 integer array s
    DECLARE 2x2 integer array sum, INITIALIZED TO 0

    // ù ��° ��� �Է� �ޱ�
    PRINT "ù ��° 2x2 ��� �Է� :"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            READ integer INTO f[i][j]
        END FOR
    END FOR

    // �� ��° ��� �Է� �ޱ�
    PRINT "�� ��° 2x2 ��� �Է� :"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            READ integer INTO s[i][j]
        END FOR
    END FOR

    // ��� ���� ���� ���� �� ��� ���
    PRINT "��� ���� ��� :"
    FOR i FROM 0 TO 1 DO
        FOR j FROM 0 TO 1 DO
            SET sum[i][j] = f[i][j] + s[i][j]
            PRINT sum[i][j] + " "   // ��� ��� (�� ���� ��ҵ��� �������� ����)
        END FOR
        PRINT newline             // �� ���� ���� �� �ٹٲ�
    END FOR
END
*/

#include <stdio.h>

int main() {

	int f[2][2], s[2][2], sum[2][2] = { 0 };

	printf("ù ��° 2x2 ��� �Է� : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &f[i][j]);
		}
	}

	printf("�� ��° 2x2 ��� �Է� : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			scanf_s("%d", &s[i][j]);
		}
	}

	printf("��� ���� ��� : \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			sum[i][j] = f[i][j] + s[i][j];
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
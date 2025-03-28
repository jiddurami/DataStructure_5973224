/*

�ǻ��ڵ�
BEGIN
    // 1. ������ ���� �Է�
    PRINT "������ ������ �Է��ϼ��� : "
    READ num

    // 2. num ũ���� �迭 N ���� �Ҵ�
    ALLOCATE array N with size num

    // 3. num���� ������ �迭�� �Է�
    PRINT "5���� ������ �Է��ϼ��� : "
    FOR i FROM 0 TO num - 1 DO
        READ N[i]
    END FOR

    // 4. ���� ������ ����� �������� ����
    FOR i FROM 0 TO num - 1 DO
        // �� �н����� ������ i���� ��Ҵ� �̹� ���ĵ�
        FOR j FROM 1 TO (num - i - 1) DO
            IF N[j - 1] > N[j] THEN
                // ������ �� ��Ҹ� ��ȯ(swap)
                temp �� N[j - 1]
                N[j - 1] �� N[j]
                N[j] �� temp
            END IF
        END FOR
    END FOR

    // 5. ���ĵ� �迭 ���
    PRINT "������������ ���ĵ� ������ : "
    FOR i FROM 0 TO num - 1 DO
        PRINT N[i] + " "
    END FOR

END
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

	int num, temp;

	printf("������ ������ �Է��ϼ��� : ");
	scanf_s("%d", &num);

	int* N = (int*)malloc(sizeof(int) * (num));
	
	printf("5���� ������ �Է��ϼ��� : \n");
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

	printf("������������ ���ĵ� ������ : \n");
	for (int i = 0; i < num; i++) {
		printf("%d ", N[i]);
	}

	return 0;
}
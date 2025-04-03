/*
n=10�� ��
fibonacci_rec(��������)
ȣ�� Ƚ�� : fibonacci_rec(10)�� 177�� ȣ���.
Fibonacci(11)=89�̹Ƿ� 2��89 - 1 = 177
ȣ�� �� ����
�Լ��� �ڱ� �ڽ��� �� ���� ��� ȣ���Ͽ� ������ �κ� ������ ������ ����ϱ� ����.
��� : n�� �󸶴��Ŀ� ���� ���ϱ޼��� ����

fibonacci_itr(��ȯ�����)
ȣ�� Ƚ�� : fibonacci_itr(10)�� 1�� ȣ���.
ȣ�� �� ����
�ݺ����� ����Ͽ� �� ���� �Լ� ȣ�� ������ ���������� ����ϱ� ����
��� : ���������� ����
*/


#include <stdio.h>
#include <stdlib.h>

// ��ȯ�� ���
int fibonacci_itr(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int f1 = 0, f2 = 1, f3;
    for (int i = 2; i <= n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f2;
}

// ����� ���
int fibonacci_rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main(void) {
    int n, method;

    while (1) {
        printf("�Ǻ���ġ ���� ��� ���� (1: �����, 2: ��ȯ��, 0: ����) : ");
        scanf_s("%d", &method);

        if (method == 0) {
            printf("���α׷��� ����Ǿ����ϴ�.\n");
            break;
        }

        printf("���� N�� �Է��ϼ��� (�����Ϸ��� 0 �Է�) : ");
        scanf_s("%d", &n);

        int result;
        if (method == 1) {
            result = fibonacci_rec(n);
            printf("F(%d) = %d (����� ���)\n", n, result);
        }
        else if (method == 2) {
            result = fibonacci_itr(n);
            printf("F(%d) = %d (��ȯ�� ���)\n", n, result);
        }
        else {
            printf("�ٽ��Է�\n");
        }
    }

    return 0;
}
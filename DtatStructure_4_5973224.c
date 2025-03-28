/*
알고리즘 : n 이하의 모든 소수를 찾는 프로그램
입력 : 정수 n
출력 : n 이하의 모든 소수

시작
    출력("정수 n을 입력하세요: ")
    입력(n)

    출력(n, " 이하의 소수: ")

    반복 num ← 2부터 n까지
        count ← 0  // 약수 개수 초기화

        반복 i ← 1부터 num까지
            만약 num을 i로 나누었을 때 나머지가 0이면
                count ← count + 1  // 약수 개수 증가
            끝 만약
        끝 반복

        만약 count = 2이면  // 나눠 떨어지는 수가 2개면 소수
            출력(num)
        끝 만약
    끝 반복

    출력(줄 바꿈)
끝
*/
#include <stdio.h>

int main() {

    int n;
    printf("정수 n을 입력하세요 : ");

    scanf_s("%d", &n);  // n 입력 받기
    printf("%d 이하의 소수 : ", n);

    // 2부터 n까지 반복하여 소수 판별하기
    for (int num = 2; num <= n; num++) {
        int count = 0;  // 각 num에 대해 count 초기화

        // num을 1부터 num까지 나누어 봄
        for (int i = 1; i <= num; i++) {
            if (num % i == 0) {  // 나누어떨어지면
                count++;  // 카운트 증가
            }
        }
        // count가 2이면 소수(1과 자기자신)
        if (count == 2) {
            printf("%d ", num);  // 소수 출력
        }
    }
    printf("\n");
    return 0;
}

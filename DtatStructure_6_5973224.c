/*  
의사코드
프로그램 시작

정수 n을 입력받음
"정수 n을 입력하세요 : " 출력

"n 이하의 소수 : " 출력

for num = 2 to n  // 2부터 n까지 반복
    count = 0  // 소수 판별을 위한 카운트 변수 초기화
    
    for i = 1 to num  // 1부터 num까지 나누어 봄
        if num % i == 0 then  // num이 i로 나누어떨어지면 
            count 증가  // 약수 개수 증가
    
    if count == 2 then  // 약수가 1과 자기 자신뿐이면
        num 출력  // 소수이므로 출력

프로그램 종료
*/

/*
시간복잡도 예측
num이 2일때 2번실행
num이 3일때 3번실행
num이 100일때 100번실행
.
.
.
num이 n일때 n번실행으로
예측 시간복잡도는 O(n^2)
*/

#include <stdio.h>

int main() {

    int n;
    printf("정수 n을 입력하세요 : ");

    scanf_s("%d", &n);  // n 입력 받기
    printf("%d 이하의 소수 : ", n);

    // 2부터 n까지 반복하여 소수 판별하기
    for (int num = 2; num <= n; num++) {
        int count = 0;  // count 초기화

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

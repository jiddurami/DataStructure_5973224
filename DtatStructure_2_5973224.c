#include <stdio.h>

int main()
{
    float num;  // 입력받을 실수형 변수 선언

    printf("실수를 입력하세요 : ");  // 실수를 입력하세요 : 메시지 출력
    scanf_s("%f", &num);  // 실수를 입력받음

    unsigned int ptr = *(unsigned int*)&num;  // 실수형을 비트 단위로 다루기 위해 unsigned int로 형변환함
    printf("부호 (1비트) : %u\n", (ptr >> 31) & 1);     // 비트를 오른쪽으로 31칸 이동하여 부호비트 출력

    printf("지수 (8비트) : "); // 지수 부분 (8비트) 메시지 출력
    for (int i = 0; i < 8; i++) 
        printf("%d", (ptr >> (23 + i)) & 1);  // 23번째 비트부터 오른쪽으로 쉬프트하며 출력
    printf("\n"); //줄바꿈


    printf("가수 (23비트) : ");    // 가수 비트 (23비트) : 메시지 출력 9번부터 31번 비트까지
    for (int i = 22; i >= 0; i--) {
        printf("%d", (ptr >> i) & 1);  // 22번 비트부터 0번 비트까지 출력
    }
    printf("\n");//줄바꿈
    return 0;  // 프로그램 종료
}
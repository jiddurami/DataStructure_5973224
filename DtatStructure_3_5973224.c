#include <stdio.h>

int main()
{
    char c[100];  // 문자열을 저장할 최대 100자 배열 c를 선언함

    printf("문자열을 입력하세요 : ");  // 메시지 출력
    scanf("%[^\n]", c);  // 공백을 포함한 문자열을 입력받기 위해 %[^\n] 사용함

    int length = strlen(c);  // 문자열의 길이를 length에 저장
    printf("문자열의 길이 : %d\n", length);  // 문자열 길이 출력

    for (int i = 0; i < length; i++)  // 문자열 길이만큼 반복
    {
        if (c[i] >= 'a' && c[i] <= 'z')  // 소문자인 경우
        {
            c[i] = c[i] - 32;  // 소문자 -> 대문자로 변환 (ASCII코드)
        }
        else if (c[i] >= 'A' && c[i] <= 'Z')  // 대문자인 경우
        {
            c[i] = c[i] + 32;  // 대문자 -> 소문자로 변환 (ASCII코드)
        }
    }

    printf("변환된 문자열 : %s", c);  // 변환된 문자열 출력
    return 0;  // 프로그램 종료
}

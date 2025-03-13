#include <stdio.h>
int main()
{
    printf("%p",-1);
}

// printf("%d",); 이런 경우는 없겠지만 이런 경우 어떻게 처리할지
// %d에는 int형인지
// printf("%c",NULL); 이런 경우는 어떻게 처리하는지
//     printf("%c",'\200'); 이럴 경우 어떻게 될지
//    printf("%x",-123); 이런 경우 음수를 어떻게 표현하는지 왜 unsigned int로 바뀌면 음수를 표현할 수 있는지 비트적으로 이해하기
// makefile 분석하기
// test폴더, .vscode파일 지우기
// 
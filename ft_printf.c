#include "printf.h"
#include "libft/libft.h"

static int jw_format(const char *format,int i,va_list ap)
{
    int count;
    count = 0;
    if(format[i] == 's' || format[i] == 'c')
    {
        count += ft_printf_str(va_arg(ap,char *));
    }
    else if(format[i] == 'p')
    {
    }
    else if(format[i] == 'd' || format[i] == 'i')
    {
        count += ft_printf_nbr(va_arg(ap,int));
    }
    else if(format[i] == 'u')
    {
    }
    else if(format[i] == 'x' || format[i] == 'X')
    {
    }
    else if(format[i] == '%')
    {
        count += write(1,"%",1);
    }
    return (count);
}
int ft_printf(const char *format, ...)
{
    int i;
    int count;
    va_list ap;

    i = 0;
    count = 0;
    va_start(ap,format);
    while(format[i])
    {
        if(format[i] == '%')
        {
            count += jw_format(format,++i,ap);
        }
        else
        {
            write(1,&format[i],1);
            count++;
        }
        i++;
    }
    va_end(ap);
    return (count);// 출력한 문자 수를 반환하도록 수정
}

// #include<stdio.h>
// int main()
// {
//     int count = ft_printf("%s!%d","asdf",123);
//     printf("\n |%d|",count);
//     // int count =printf("\n");

// }
//c는 문자 한개
//s는 문자열
//p는 포인터 주소 출력
//d는 정수
//i는 d랑 동일
//u는 부호 없는 10진수 정수
//x는 16진수 소문자
//X는 16진수 대문자로 출력
//cspdiuxX
//숫자
//문자
#include "printf.h"
#include "libft/libft.h"

static int jw_format(const char *format,int i,va_list ap)
{
    int count;
    count = 0;
    if(format[i] == 's' || format[i] == 'c')
    {
        count += ft_printf_str(va_arg(ap,char *), format[i]);
    }
    else if(format[i] == 'p')
    {
        count += ft_printf_ptn(va_arg(ap,void *));
    }
    else if(format[i] == 'd' || format[i] == 'i')
    {
        count += ft_printf_nbr(va_arg(ap,int));
    }
    else if(format[i] == 'u')
    {
        count += ft_printf_unsigned(va_arg(ap,unsigned int));
    }
    else if(format[i] == 'x' || format[i] == 'X')
    {
        count += ft_printf_hex(va_arg(ap,long), format[i]);
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
    return (count);
}

// #include<stdio.h>
// int main()
// {
//     // printf("\n |%d|",count);
//     int i = 10;
//     int *p = &i;
//     ft_printf("%p\n",p);
//     int count =printf("%p",p);
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
// 고려해야할것 실제 printf에 들어가는 정수형 타입 int형인지 만약 int형을 초과해버리면 어떤 일이 일어나는지 조사해야함
// NULL포인터가 들어갔을 때 어떻게 동작하는지
// 다 만들고 일단 예외를 생각해서 예외처리
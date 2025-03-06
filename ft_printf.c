#include "printf.h"

#include <string.h>
void	ft_putnbr_fd(int x, int fd)
{
	long long	n;
	char		s;

	if (fd < 0)
		return ;
	n = (long long )x;
	if (x < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((int)(n / 10), fd);
		s = (char)((n % 10) + '0');
		write(fd, &s, 1);
	}
	else if (n < 10 && n != 0)
	{
		s = (char)((n % 10) + '0');
		write(fd, &s, 1);
	}
	s = '0';
	if (n == 0)
		write(fd, &s, 1);
}
void ft_printf_str(char * str)
{
    write(1,str,strlen(str));
}
static void jw_format(const char *format,int i,va_list ap)
{
    if(format[i] == 's' || format[i] == 'c')
    {
        ft_printf_str(va_arg(ap,char *));
    }
    else if(format[i] == 'p')
    {
    }
    else if(format[i] == 'd' || format[i] == 'i')
    {
        ft_putnbr_fd(va_arg(ap,int),1);
    }
    else if(format[i] == 'u')
    {
    }
    else if(format[i] == 'x' || format[i] == 'X')
    {
    }        
}
int ft_printf(const char *format, ...)
{
    int i;
    int j;
    char *str;
    va_list ap;

    i = 0;
    j = 0;
    va_start(ap,format);
    str = malloc(strlen(format) * sizeof(char));
    while(format[i])
    {
        if(format[i] == '%')
        {
            jw_format(format,++i,ap);
        }
        else
        {
            str[j++] = format[i];
        }
        i++;
    }
    write(1,str,strlen(str));
    va_end(ap);
    return ((int)strlen(format));// 출력한 문자 수를 반환하도록 수정
}

#include<stdio.h>
int main()
{
    ft_printf("%dxx%s\n",111,"world\t");
    // printf("%dxx%s",111,"world\n");

}
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
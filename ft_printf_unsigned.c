#include "printf.h"
#include "libft/libft.h"

size_t getCount_unsigned(unsigned int x)
{
    size_t count;

    count = 0;
    while (x)
    {
        x /= 10;
        count++;
    }
    return (count);
}
char *ft_itoa_unsigned(unsigned int x)
{
    char *str;
    size_t len;

    len = getCount_unsigned(x);
    str = malloc(len + 1);
    str[len--] = '\0';
	if (x == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (x > 0)
	{
		str[len] = (x % 10) + '0';
		x /= 10;
		len--;
	}
    return str;
}
int ft_printf_unsigned(unsigned int x)
{
    char *str;
    int count;

    count = 0;
    str = malloc(getCount_unsigned(x) + 1);
    str = ft_itoa_unsigned(x);
    count += write(1,str,ft_strlen(str));
    return (count);
}
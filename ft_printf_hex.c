#include "libft/libft.h"
#include "printf.h"

size_t getCount_hex(unsigned int x)
{
    size_t count;

    count = 0;
    while(x)
    {
        x = x / 16;
        count++;
    }
    return (count);
}
char *ft_itoh(unsigned int x, char format)
{
    int mod;
    int len;
    char *hex;

    len = getCount_hex(x);
    hex = malloc(getCount_hex(x) + 1);
    hex[len--] = '\0';  
    while (x)
    {
        mod = x % 16;
        if(mod < 10)
            hex[len--] = '0' + mod;
        else
        {
            if(format == 'x')
            {
                mod = mod - 10;
                hex[len--] = 'a' + mod;
            }
            else
            {
                mod = mod - 10;
                hex[len--] = 'A' + mod;
            }
        }
        x = x / 16;
    }
    return (hex);
}

int ft_printf_hex(int x,char format)
{
    unsigned int num;
    int count;
    char *hex;

    count = 0;
    if(x == 0)
        count += write(1,"0",1);
    num = (unsigned int)x;
    hex = ft_itoh(num,format);
    count += write(1,hex,ft_strlen(hex));
    free(hex);
    return (count);
}
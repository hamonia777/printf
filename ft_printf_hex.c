#include "libft/libft.h"
#include "printf.h"

size_t getCount_hex(int x)
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
    int i;
    // unsigned int num;
    char *hex;

    i = 0;
    // num = x;
    hex = malloc(getCount_hex(x) + 1);    
    while (x)
    {
        mod = x % 16;
        if(mod < 10)
            hex[i++] = '0' + mod;
        else
        {
            if(format == 'x')
            {
                mod = mod - 10;
                hex[i++] = 'a' + mod;
            }
            else
            {
                mod = mod - 10;
                hex[i++] = 'A' + mod;
            }
        }
        x = x / 16;
    }
    hex[i] = '\0';
    return (hex);
}

int ft_printf_hex(int x,char format)
{
    unsigned int num;
    int i;
    int count;
    char *hex;

    count = 0;
    num = (unsigned int)x;
    hex = malloc(getCount_hex(num) + 1);
    hex = ft_itoh(num,format);
    i = (int)ft_strlen(hex);
    while (i >= 0)
    {
        count += write(1,&hex[i],1);
        i--;
    }
    free(hex);
    return (count);
}
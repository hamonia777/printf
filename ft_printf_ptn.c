#include "printf.h"
#include "libft/libft.h"

size_t getCount_point(unsigned long x)
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
char *ft_itoh_point(unsigned long x)
{
    int mod;
    int i;
    char *hex;

    i = 0;
    hex = malloc(getCount_point(x) + 1);    
    while (x)
    {
        mod = x % 16;
        if(mod < 10)
            hex[i++] = '0' + mod;
        else
        {
            mod = mod - 10;
            hex[i++] = 'a' + mod;
        }
        x = x / 16;
    }
    hex[i] = '\0';
    return (hex);
}

 int ft_printf_ptn(void *x)
 {
    int count;
    unsigned long address = (unsigned long)x;
    char *str;

    count = 0;
    str = malloc(getCount_point(address));
    str = ft_itoh_point(address);
    count += write(1,"0x",2);
    count += write(1,str,ft_strlen(str));
    return (count);
 }
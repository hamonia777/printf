#include "printf.h"
#include "libft/libft.h"
#include<stdint.h>
size_t getCount_point(uintptr_t x)
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
char *ft_itoh_point(uintptr_t x)
{
    int mod;
    int len;
    char *hex;

    len = getCount_point(x);
    hex = malloc(len + 1);    
    hex[len--] = '\0';
    while (x)
    {
        mod = x % 16;
        if(mod < 10)
            hex[len--] = '0' + mod;
        else
        {
            mod = mod - 10;
            hex[len--] = 'a' + mod;
        }
        x = x / 16;
    }
    return (hex);
}

 int ft_printf_ptn(void *x)
 {
    int count;
    uintptr_t addr = (uintptr_t)x;
    char *str;

    count = 0;
    if(x == NULL)
    {
        count += write(1,"(nil)",5);
        return count;
    }
    str = ft_itoh_point(addr);
    count += write(1,"0x",2);
    count += write(1,str,ft_strlen(str));
    free(str);
    return (count);
 }
 
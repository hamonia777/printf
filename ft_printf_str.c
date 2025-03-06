#include "printf.h"
#include "libft/libft.h"

int ft_printf_str(char * str)
{
    int i;
    i = 0;
    i = write(1,str,ft_strlen(str));
    return (i);
}
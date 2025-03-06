#include "printf.h"
#include "libft/libft.h"

void ft_printf_str(char * str)
{
    write(1,str,ft_strlen(str));
}
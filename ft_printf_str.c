#include "printf.h"
#include "libft/libft.h"

int ft_printf_str(char * str, char format)
{
    int i;
    char word;
    i = 0;
    if (str == NULL)
    {
        i += write(1,"(null)",6);
        return (i);
    }
    if(format == 's')
        i += write(1,str,ft_strlen(str));
    return (i);
}
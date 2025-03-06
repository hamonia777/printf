#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *, ...);
void ft_printf_nbr(int nbr);
void ft_printf_str(char * str);

#endif
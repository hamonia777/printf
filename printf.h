#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

int ft_printf(const char *, ...);
int ft_printf_nbr(int nbr);
int ft_printf_str(char * str);
int ft_printf_ptn(void *x);
int ft_printf_hex(int x,char format);
int ft_printf_unsigned(unsigned int x);

#endif
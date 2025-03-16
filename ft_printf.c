/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:12:20 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/14 22:34:06 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	jw_format(const char *format, int i, va_list ap)
{
	unsigned char	word;
	int				count;

	count = 0;
	if (format[i] == 's')
		count += ft_printf_str(va_arg(ap, char *), format[i]);
	else if (format[i] == 'c')
	{
		word = (char)va_arg(ap, int);
		count += write(1, &word, 1);
	}
	else if (format[i] == 'p')
		count += ft_printf_ptn(va_arg(ap, void *));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_printf_nbr(va_arg(ap, int));
	else if (format[i] == 'u')
		count += ft_printf_unsigned(va_arg(ap, unsigned int));
	else if (format[i] == 'x' || format[i] == 'X')
		count += ft_printf_hex(va_arg(ap, unsigned int), format[i]);
	else if (format[i] == '%')
		count += write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += jw_format(format, ++i, ap);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

// #include<stdio.h>
// int main()
// {
//     // printf("\n |%d|",count);
//     int i = 10;
//     int *p = &i;
//     ft_printf("%p\n",p);
//     int count =printf("%p",p);
// }

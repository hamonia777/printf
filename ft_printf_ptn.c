/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:45:04 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/14 20:08:03 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static size_t	getcount_point(unsigned long x)
{
	size_t	count;

	count = 0;
	while (x)
	{
		x = x / 16;
		count++;
	}
	return (count);
}

static char	*ft_itoh_point(unsigned long x)
{
	int		mod;
	int		len;
	char	*hex;

	len = getcount_point(x);
	hex = malloc(len + 1);
	if (!hex)
		return (NULL);
	hex[len--] = '\0';
	while (x)
	{
		mod = x % 16;
		if (mod < 10)
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

int	ft_printf_ptn(void *x)
{
	unsigned long		addr;
	int					count;
	char				*str;

	count = 0;
	addr = (unsigned long)x;
	if (x == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	str = ft_itoh_point(addr);
	count += write(1, "0x", 2);
	count += write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

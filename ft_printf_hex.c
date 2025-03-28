/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:53:48 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/14 20:10:31 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static size_t	getcount_hex(unsigned int x)
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

static char	*ft_itoh(unsigned int x, char format)
{
	int		mod;
	int		len;
	char	*hex;

	len = getcount_hex(x);
	hex = malloc(getcount_hex(x) + 1);
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
			if (format == 'x')
				hex[len--] = 'a' + mod - 10;
			else
				hex[len--] = 'A' + mod - 10;
		}
		x = x / 16;
	}
	return (hex);
}

int	ft_printf_hex(unsigned int x, char format)
{
	char				*hex;
	int					count;

	count = 0;
	if (x == 0)
		count += write(1, "0", 1);
	hex = ft_itoh(x, format);
	count += write(1, hex, ft_strlen(hex));
	free(hex);
	return (count);
}

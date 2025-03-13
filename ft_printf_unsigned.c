/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:56:59 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/13 20:34:28 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

size_t	getcount_unsigned(unsigned int x)
{
	size_t	count;

	count = 0;
	while (x)
	{
		x /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_unsigned(unsigned int x)
{
	size_t		len;
	char		*str;

	len = getcount_unsigned(x);
	str = malloc(len + 1);
	if(!str)
		return (NULL);
	str[len--] = '\0';
	if (x == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (x > 0)
	{
		str[len] = (x % 10) + '0';
		x /= 10;
		len--;
	}
	return (str);
}

int	ft_printf_unsigned(unsigned int x)
{
	char	*str;
	int		count;

	count = 0;
	str = ft_itoa_unsigned(x);
	count += write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:55:15 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/13 18:56:44 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_str(char *str, char format)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += write(1, "(null)", 6);
		return (i);
	}
	if (format == 's')
		i += write(1, str, ft_strlen(str));
	return (i);
}

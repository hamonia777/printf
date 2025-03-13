/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:38:55 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/13 18:41:27 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

int	ft_printf_nbr(int nbr)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_itoa(nbr);
	count += write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

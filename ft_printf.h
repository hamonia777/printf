/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:38:12 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/14 20:40:12 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printf_nbr(int nbr);
int	ft_printf_str(char *str, char format);
int	ft_printf_ptn(void *x);
int	ft_printf_hex(unsigned int x, char format);
int	ft_printf_unsigned(unsigned int x);

#endif

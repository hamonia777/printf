/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:34:51 by jinwpark          #+#    #+#             */
/*   Updated: 2025/03/13 20:45:39 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include<stdint.h>

int	ft_printf(const char *format, ...);
int	ft_printf_nbr(int nbr);
int	ft_printf_str(char *str, char format);
int	ft_printf_ptn(void *x);
int	ft_printf_hex(int x, char format);
int	ft_printf_unsigned(unsigned int x);

#endif

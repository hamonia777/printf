/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinwpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:11:55 by jinwpark          #+#    #+#             */
/*   Updated: 2025/02/11 21:05:02 by jinwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int num);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *src, int c, size_t n);
void	*ft_memcpy(void *dest, const void *source, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *str, int val);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t elt_count, size_t elt_size);
char	*ft_strdup(const char *s);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int x, int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif

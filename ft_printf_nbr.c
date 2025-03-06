#include "printf.h"
#include "libft/libft.h"

static int	jw_getlength(long long i)
{
	int	len;

	len = 0;
	if (i <= 0)
		len++;
	while (i != 0)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static void	jw_convert(long long n, char *str, int len)
{
	int	i;

	i = len - 1;
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

char	*ft_itoa(int x)
{
	char		*str;
	long long	n;
	int			len;

	n = (long long)x;
	len = jw_getlength(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	jw_convert(n, str, len);
	str[len] = '\0';
	return (str);
}

int ft_printf_nbr(int nbr)
{
    int count;
    char *str;

    count = 0;
    str = ft_itoa(nbr);
    count += write(1,str,ft_strlen(str));
    return (count);
}
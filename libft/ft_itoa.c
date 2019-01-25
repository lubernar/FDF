/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:21:46 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/20 11:31:53 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ifneg(int len, int n, char *str)
{
	n = -n;
	str[0] = '-';
	while (len > 0)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = count_n_len(n);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		ifneg(len, n, str);
	else
	{
		while (len >= 0)
		{
			str[len] = (n % 10) + '0';
			n = n / 10;
			len--;
		}
	}
	return (str);
}

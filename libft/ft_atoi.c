/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 12:38:52 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/15 16:44:21 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long i;
	long transformed;
	long neg;

	neg = 1;
	i = 0;
	transformed = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		transformed = transformed * 10;
		transformed = (transformed + str[i]) - '0';
		i++;
		if (transformed < 0)
			return (neg == 1) ? -1 : 0;
	}
	return (neg * transformed);
}

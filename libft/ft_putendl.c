/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:43:33 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/14 16:46:15 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

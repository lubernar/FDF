/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:01:37 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/23 16:02:39 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int c)
{
	char	*s;
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (s1[i])
	{
		length++;
		i++;
	}
	if ((s = malloc(sizeof(char) * (length + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != c)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

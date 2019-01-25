/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:02:12 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/12 11:40:27 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
		return (char*)(&s[ft_strlen(s)]);
	while ((unsigned char)s[i] != (unsigned char)c && s[i])
		i++;
	if (s[i] == '\0')
		return (NULL);
	return ((char*)&s[i]);
}

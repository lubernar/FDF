/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:25:58 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/19 16:48:45 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_without_spaces(const	char *str)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(str) - 1;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
		i++;
	if (str[i] == '\0')
		return (i);
	while ((str[len] == ' ' || str[len] == '\n' || str[len] == '\t') && str[i])
	{
		len--;
		i++;
	}
	len = ft_strlen(str);
	return (len - i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_len_without_spaces(s);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while (j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

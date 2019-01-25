/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:18:04 by lubernar          #+#    #+#             */
/*   Updated: 2019/01/24 15:26:16 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t i;
	size_t words;

	i = 0;
	words = 0;
	if (str[i] != c && str[i] != '\0')
	{
		words++;
		i++;
	}
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1])
			words++;
		i++;
	}
	return (words);
}

static size_t	count_letters(size_t i, const char *str, char c)
{
	size_t letters;

	letters = 0;
	while (str[i] == c && str[i])
		i++;
	while (str[i - 1] != c && i != 0)
		i++;
	while (str[i] != c && str[i])
	{
		letters++;
		i++;
	}
	return (letters);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**str;
	size_t	len;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = count_words(s, c);
	if ((str = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
		return (NULL);
	while (s[i] && j < len)
	{
		while (s[i] == c && s[i])
			i++;
		str[j] = ft_strsub(s, i, count_letters(i, s, c));
		j++;
		i = count_letters(i, s, c) + i;
	}
	str[j] = 0;
	return (str);
}

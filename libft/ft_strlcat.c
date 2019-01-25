/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:52:52 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/19 17:47:09 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t destlen;

	destlen = ft_strlen(dst);
	if (size > destlen)
	{
		ft_strncat(dst, src, size - destlen - 1);
		return (size_t)(ft_strlen(src) + destlen);
	}
	else
		return (size_t)(ft_strlen(src) + size);
}

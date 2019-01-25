/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:23:04 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/19 17:23:09 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((unsigned char*)src < (unsigned char*)dest
		&& (unsigned char*)src + ft_strlen(src) > (unsigned char*)dest)
	{
		while (n--)
			((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

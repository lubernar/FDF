/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:16:07 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/15 13:35:46 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*(alst))->next != NULL)
	{
		del((*(alst))->content, (*(alst))->content_size);
		free(*alst);
		*alst = (*(alst))->next;
	}
	del((*(alst))->content, (*(alst))->content_size);
	free(*alst);
	*alst = NULL;
}

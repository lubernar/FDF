/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:52:56 by lubernar          #+#    #+#             */
/*   Updated: 2018/11/15 15:27:22 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *begin;

	map = f(lst);
	begin = map;
	while (lst->next != NULL)
	{
		map->next = f(lst->next);
		lst = lst->next;
		map = map->next;
	}
	return (begin);
}

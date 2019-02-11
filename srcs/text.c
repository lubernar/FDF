/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 15:25:39 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/06 14:49:21 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	string_put(t_all *all)
{
	mlx_string_put(all->mlx, all->win, 20, 20, 16777215,
			"different views : p / i");
	mlx_string_put(all->mlx, all->win, 20, 50, 16777215,
			"Move map with arrows");
	mlx_string_put(all->mlx, all->win, 20, 80, 16777215,
			"Zoom : + / -");
	mlx_string_put(all->mlx, all->win, 20, 110, 16777215,
			"Depth : / and *");
}

void	error(char *str)
{
	ft_putstr(str);
	exit(0);
}

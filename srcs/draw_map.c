/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:16:59 by lubernar          #+#    #+#             */
/*   Updated: 2019/01/25 17:18:05 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_map(t_all *all)
{
	int		x;
	int		y;
	int		lines;
	int		z;

	z = 20;
	x = 1;
	y = 1;
	while (y < all->nb_lines)
	{
		while (all->tab[y][x] != 2147483647)
		{
			all->x1 = (x - 1) * z + all->tab[y - 1][x - 1] * z;
			all->y1 = (y - 1) * z + all->tab[y - 1][x - 1] * z;
			all->x2 = x * z + all->tab[y - 1][x] * z;
			all->y2 = (y - 1) * z + all->tab[y - 1][x] * z;
			draw_line(all);
			all->x2 = (x - 1) * z + all->tab[y][x - 1] * z;
			all->y2 = y * z + all->tab[y][x - 1] * z;
			draw_line(all);
			x++;
		}
			y++;
			x = 1;
	}
}

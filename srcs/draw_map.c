/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:16:59 by lubernar          #+#    #+#             */
/*   Updated: 2019/01/30 14:42:01 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_map(t_all *all)
{
	int			x;
	int			y;
	int			z;
	static int	istrue;

	if (!istrue)
	{
		all->z = 10;
		all->deepth = 1;
	}
		x = 1;
	y = 1;
	istrue = 1;
	while (y < all->nb_lines)
	{
		while (all->tab[y][x] != 2147483647)
		{
			all->x1 = (x - 1) * all->z + all->tab[y - 1][x - 1] * (all->z / all->deepth);
			all->y1 = (y - 1) * all->z + all->tab[y - 1][x - 1] * (all->z / all->deepth);
			all->x2 = x * all->z + all->tab[y - 1][x] * (all->z / all->deepth);
			all->y2 = (y - 1) * all->z + all->tab[y - 1][x] * (all->z / all->deepth);
			draw_line(all);
			all->x2 = (x - 1) * all->z + all->tab[y][x - 1] * (all->z / all->deepth);
			all->y2 = y * all->z + all->tab[y][x - 1] * (all->z / all->deepth);
			draw_line(all);
			x++;
		}
			y++;
			x = 1;
	}
}

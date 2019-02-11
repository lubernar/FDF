/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:16:59 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/07 18:32:51 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		color_map(t_all *all, int y, int x, int **tab)
{
	if (abs(tab[y][x] * all->dep) >= 0 && abs(tab[y][x] * all->dep) < 4)
		all->color = 65280;
	if (abs(tab[y][x] * all->dep) >= 4 && abs(tab[y][x] * all->dep) < 8)
		all->color = 65510;
	if (abs(tab[y][x] * all->dep) >= 8 && abs(tab[y][x] * all->dep) < 12)
		all->color = 1917670;
	if (abs(tab[y][x] * all->dep) >= 12 && abs(tab[y][x] * all->dep) < 16)
		all->color = 13124326;
	if (abs(tab[y][x] * all->dep) >= 16 && abs(tab[y][x] * all->dep) < 20)
		all->color = 16711680;
	if (abs(tab[y][x] * all->dep) >= 20 && abs(tab[y][x] * all->dep < 24))
		all->color = 16737290;
	if (abs(tab[y][x] * all->dep) >= 24 && abs(tab[y][x] * all->dep < 28))
		all->color = 15788810;
	if (abs(tab[y][x] * all->dep) >= 28)
		all->color = 16777215;
}

void		iso_draw_line(t_all *all, int x, int y)
{
	all->centerx = all->width / 2 - ((all->xmax / 2) - all->nb_lines / 2)
		* all->z + all->movex;
	all->centery = all->length / 2 - ((all->nb_lines / 2) + all->xmax / 2)
		* all->z + all->movey;
	all->x1 = all->centerx + ((x - 1) - (y - 1)) * all->z;
	all->y1 = all->centery + ((x - 1) + (y - 1)) * all->z
		- all->tab[y - 1][x - 1] * all->dep;
	all->x2 = all->centerx + ((x) - (y - 1)) * all->z;
	all->y2 = all->centery + ((x) + (y - 1)) * all->z - all->tab[y - 1][x]
		* all->dep;
}

void		draw_iso(t_all *all)
{
	int			x;
	int			y;
	static int	istrue;

	y = 1;
	if (!istrue)
		all = initialize_all(all);
	istrue = 1;
	while (y < all->nb_lines)
	{
		x = 1;
		while (x < all->xmax)
		{
			iso_draw_line(all, x, y);
			color_map(all, y, x, all->tab);
			draw_line(all);
			all->x2 = all->centerx + ((x - 1) - y) * all->z;
			all->y2 = all->centery + ((x - 1) + y) * all->z - all->tab[y][x - 1]
				* all->dep;
			color_map(all, y, x - 1, all->tab);
			draw_line(all);
			x++;
		}
		y++;
	}
}

void		map_draw_line(t_all *all, int x, int y)
{
	all->centerx = all->width / 2 - (all->xmax / 2) * all->z + all->movex;
	all->centery = all->length / 2 - (all->nb_lines / 2) * all->z + all->movey;
	all->x1 = all->centerx + (x - 1) * all->z + all->tab[y - 1][x - 1]
		* all->dep;
	all->y1 = all->centery + (y - 1) * all->z + all->tab[y - 1][x - 1]
		* all->dep;
	all->x2 = all->centerx + x * all->z + all->tab[y - 1][x] * all->dep;
	all->y2 = all->centery + (y - 1) * all->z + all->tab[y - 1][x]
		* all->dep;
}

void		draw_map(t_all *all)
{
	int			x;
	int			y;
	static int	istrue;

	y = 1;
	if (!istrue)
		all = initialize_all(all);
	istrue = 1;
	while (y < all->nb_lines)
	{
		x = 1;
		while (x < all->xmax)
		{
			map_draw_line(all, x, y);
			color_map(all, y, x, all->tab);
			draw_line(all);
			all->x2 = all->centerx + (x - 1) * all->z + all->tab[y][x - 1]
				* all->dep;
			all->y2 = all->centery + y * all->z + all->tab[y][x - 1] * all->dep;
			color_map(all, y, x - 1, all->tab);
			draw_line(all);
			x++;
		}
		y++;
	}
}

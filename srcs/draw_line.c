/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:07:10 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/08 10:24:20 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_putpixel(t_all *all)
{
	if (all->x < 0 || all->y < 0 || all->width <= all->x
			|| all->length <= all->y)
		return ;
	all->ac == 3 ? all->color = ft_atoi(all->av[2]) : all->color;
	all->image_s[all->y * all->width + all->x] = all->color;
}

int		horizontal_line(int error, t_all *all)
{
	error = all->dx / 2;
	while (all->x != all->x2)
	{
		all->x += all->xinc;
		error += all->dy;
		if (error >= all->dx)
		{
			error -= all->dx;
			all->y += all->yinc;
		}
		ft_putpixel(all);
	}
	return (error);
}

int		vertical_line(int error, t_all *all)
{
	error = all->dy / 2;
	while (all->y != all->y2)
	{
		all->y += all->yinc;
		error += all->dx;
		if (error >= all->dy)
		{
			error -= all->dy;
			all->x += all->xinc;
		}
		ft_putpixel(all);
	}
	return (error);
}

void	draw_line(t_all *all)
{
	int		error;

	error = 0;
	all->x = all->x1;
	all->y = all->y1;
	all->dx = all->x2 - all->x1;
	all->dy = all->y2 - all->y1;
	all->xinc = (all->dx > 0) ? 1 : -1;
	all->yinc = (all->dy > 0) ? 1 : -1;
	all->dx = abs(all->dx);
	all->dy = abs(all->dy);
	if (all->dx > all->dy)
		error = horizontal_line(error, all);
	else
		error = vertical_line(error, all);
}

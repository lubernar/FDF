/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:03:07 by lubernar          #+#    #+#             */
/*   Updated: 2019/01/25 15:49:18 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
		mlx_pixel_put(all->mlx, all->win, all->x, all->y, 255 * 254);
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
		mlx_pixel_put(all->mlx, all->win, all->x, all->y, 255 * 254);
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
		horizontal_line(error, all);
	else
		error = vertical_line(error, all);
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 1)
	{
		all->x1 = x;
		all->y1 = y;
		mlx_pixel_put(all->mlx, all->win, all->x1, all->y1, 255 * 254 * 255);
	}
	if (button == 2)
	{
		all->x2 = x;
		all->y2 = y;
		draw_line(all);
	}
	return (0);
}

int	deal_key(int key, t_all *all)
{
	if (key == 53)
		exit (0);
	draw_map(all);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		fd;
	t_all	all;

	fd = open(av[1], O_RDONLY);
	(void)ac;
	all.nb_lines = count_lines(fd, av);
	all.tab = read_map(fd, av, all.nb_lines);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
	all.win = win_ptr;
	all.mlx = mlx_ptr;
	mlx_mouse_hook(win_ptr, mouse_hook, &all);
	mlx_key_hook(win_ptr, deal_key, &all);
	mlx_loop(mlx_ptr);
	return (0);
}

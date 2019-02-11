/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:08:11 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/10 13:19:18 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_all	*initialize_all(t_all *all)
{
	all->z = 5;
	all->dep = 1;
	all->movex = 0;
	all->movey = 0;
	all->width = 1500;
	all->length = 1000;
	return (all);
}

int		mouse_hook(int button, int x, int y, t_all *all)
{
	if (button == 1)
	{
		all->x1 = x;
		all->y1 = y;
	}
	if (button == 2)
	{
		all->x2 = x;
		all->y2 = y;
		draw_line(all);
	}
	mlx_put_image_to_window(all->image_s, all->win, all->image_ptr, 0, 0);
	string_put(all);
	return (0);
}

int		deal_key(int key, t_all *all)
{
	static int	map;

	ft_bzero(all->image_s, all->width * all->length * 4);
	if (key == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	key == 69 ? all->z += 1 : all->z;
	key == 78 ? all->z -= 1 : all->z;
	key == 67 ? all->dep-- : all->dep;
	key == 75 ? all->dep++ : all->dep;
	key == 124 ? all->movex += (all->width * 2) / 100 : all->movex;
	key == 123 ? all->movex -= (all->width * 2) / 100 : all->movex;
	key == 125 ? all->movey += (all->width * 2) / 100 : all->movey;
	key == 126 ? all->movey -= (all->width * 2) / 100 : all->movey;
	key == 35 ? map = 0 : map;
	key == 34 ? map = 1 : map;
	map == 0 ? draw_map(all) : draw_iso(all);
	mlx_put_image_to_window(all->image_s, all->win, all->image_ptr, 0, 0);
	string_put(all);
	return (0);
}

int		valid_file(char **av)
{
	int	i;
	int	len;
	int	j;

	len = 0;
	i = 0;
	while (av[1][i] != '.' && av[1][i])
		i++;
	j = i + 1;
	while (av[1][i])
	{
		i++;
		len++;
	}
	len < 3 ? error("Nom de fichier invalide.\n") : len;
	if (av[1][j] == 'f' && av[1][j + 1] == 'd' && av[1][j + 2] == 'f')
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_all	all;

	fd = open(av[1], O_RDONLY);
	fd == -1 ? error("Nom de fichier invalide.\n") : fd;
	initialize_all(&all);
	valid_file(av) == 0 ? error("Nom de fichier invalide.\n") : valid_file(av);
	ac > 3 ? error("Usage : ./fdf <file.fdf> <color>\n") : ac;
	all.ac = ac;
	all.av = av;
	all.nb_lines = count_lines(fd, av);
	all.tab = read_map(fd, all.nb_lines);
	all.xmax = xmax(all.tab);
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, all.width, all.length, "FDF");
	all.image_ptr = mlx_new_image(all.mlx, all.width, all.length);
	all.image_s = (unsigned int *)mlx_get_data_addr(all.image_ptr, &(all.bpp),
			&(all.s_l), &(all.end));
	mlx_mouse_hook(all.win, mouse_hook, &all);
	string_put(&all);
	mlx_hook(all.win, 2, 0, deal_key, &all);
	mlx_loop(all.mlx);
	return (0);
}

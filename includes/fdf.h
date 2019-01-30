/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:21:22 by lubernar          #+#    #+#             */
/*   Updated: 2019/01/30 14:35:06 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include <mlx.h>
#include <math.h>
#include "../includes/get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_all
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		ytab;
	int		xtab;
	int		**tab;
	int		nb_lines;
	int		xinc;
	int		yinc;
	int		z;
	int		deepth;
	void	*mlx;
	void	*win;
}				t_all;

int				horizontal_line(int error, t_all *all);
int				vertical_line(int error, t_all *all);
void			draw_line(t_all *all);
int				count_lines(int fd, char **av);
int				**read_map(const int fd, char **av, int nb_lines);
int				count_words(char **str);
void			draw_map(t_all *all);

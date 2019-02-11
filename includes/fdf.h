/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:21:22 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/08 15:32:26 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include "../includes/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_all
{
	int					x;
	int					y;
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					dx;
	int					dy;
	int					xmax;
	int					width;
	int					length;
	int					bpp;
	int					s_l;
	int					end;
	void				*image_ptr;
	unsigned int		*image_s;
	int					ytab;
	int					xtab;
	int					**tab;
	int					nb_lines;
	int					movex;
	int					movey;
	int					centerx;
	int					centery;
	int					xinc;
	int					yinc;
	int					z;
	int					dep;
	int					color;
	void				*mlx;
	void				*win;
	int					ac;
	char				**av;
}						t_all;

void					draw_iso(t_all *all);
void					draw_map(t_all *all);
int						horizontal_line(int error, t_all *all);
int						vertical_line(int error, t_all *all);
void					draw_line(t_all *all);
int						count_lines(int fd, char **av);
int						**read_map(const int fd, int nb_lines);
int						count_words(char **str);
int						xmax(int **tab);
void					string_put(t_all *all);
t_all					*initialize_all(t_all *all);
void					error(char *str);

#endif

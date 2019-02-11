/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:32:41 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/07 16:06:36 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_words(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		count_lines(int fd, char **av)
{
	int		nb_lines;
	char	*line;

	fd = open(av[1], O_RDONLY);
	nb_lines = 0;
	while (get_next_line(fd, &line))
	{
		nb_lines++;
		free(line);
	}
	close(fd);
	return (nb_lines);
}

int		xmax(int **tab)
{
	int	j;
	int	xmax;

	xmax = 0;
	j = 0;
	if (tab[0] == NULL)
		return (0);
	while (tab[0][j] != 2147483647)
	{
		j++;
		xmax++;
	}
	return (xmax);
}

int		str_to_tab(t_all *all, char **str, char *line, int xtab)
{
	int	istrue;

	istrue = 1;
	while (str[xtab])
	{
		all->tab[all->ytab][xtab] = ft_atoi(str[xtab]);
		xtab++;
		free(str[xtab - 1]);
	}
	free(str);
	free(line);
	all->tab[all->ytab++][xtab] = 2147483647;
	return (istrue);
}

int		**read_map(const int fd, int nb_lines)
{
	char	*line;
	char	**str;
	int		j;
	t_all	all;
	int		istrue;

	j = 0;
	all.ytab = 0;
	istrue = 0;
	if ((all.tab = (int**)malloc(sizeof(int*) * (nb_lines + 1))) == NULL)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		all.xtab = 0;
		while (!ft_isdigit(line[j]) && line[j])
			j++;
		line[j] == '\0' ? error("Fichier invalide.\n") : line[j];
		if (ft_isdigit(line[j]) || line[j] == '-')
			str = ft_strsplit(line, ' ');
		if (!(all.tab[all.ytab] = malloc(sizeof(int) * (count_words(str) + 1))))
			return (NULL);
		istrue = str_to_tab(&all, str, line, all.xtab);
	}
	!istrue ? error("Fichier invalide.\n") : all.tab[0];
	return (all.tab);
}

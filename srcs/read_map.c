/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:32:41 by lubernar          #+#    #+#             */
/*   Updated: 2019/01/25 17:43:05 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_words(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i + 1);
}

int		count_lines(int fd, char **av)
{
	int nb_lines;
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

int		**read_map(const int fd, char **av, int nb_lines)
{
	char	*line;
	char	**str;
	int		j;
	t_all	all;
	
	j = 0;
	all.ytab = 0;
	if ((all.tab = (int**)malloc(sizeof(int*) * (nb_lines + 1))) == NULL)
		return (NULL);
	if ((str = (char**)malloc(sizeof(char*) * (nb_lines + 1))) == NULL)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		all.xtab = 0;
		if (ft_isdigit(line[j]) || line[j] == '-')
			str = ft_strsplit(line, ' ');
		if (!(all.tab[all.ytab] = malloc(sizeof(int) * (count_words(str)))))
			return (NULL);
		while (str[all.xtab])
		{
			all.tab[all.ytab][all.xtab] = ft_atoi(str[all.xtab]);
			all.xtab++;
		}
		all.tab[all.ytab][all.xtab] = 2147483647;
		all.ytab++;
	}
	free(line);
	return (all.tab);
}

/*int	main(int ac, char **av)
{
	int fd;
	(void)ac;
	int	i;
	int j;
	int **tab;
	char	*line;
	int nb_line;

	j = 0;
	t_all.all.;
	i = 0;
	fd = open(av[1], O_RDONLytab);
	printf("%d\n", count_lines(fd, av));
	all..nb_lines = count_lines(fd, av);
	//nb_line = all.->nb_lines;
	tab = read_all.fd, av, all..nb_lines);
	while (i < all..nb_lines)
	{
		while (tab[i][j] != -2147483648)
		{
			printf("%d ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
	return (0);
}*/

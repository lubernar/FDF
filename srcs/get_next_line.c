/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:38:33 by lubernar          #+#    #+#             */
/*   Updated: 2019/02/07 15:46:28 by lubernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_line(char *s, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (s[i] != c)
		i++;
	if (!(new = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int		ft_ret(char **line, char **tmp, int new)
{
	char	*old;

	if (new == 0 && ft_strlen(*tmp) == 0)
	{
		*line = NULL;
		return (0);
	}
	if (ft_strchr(*tmp, '\n') != NULL)
	{
		old = *tmp;
		*line = ft_line(*tmp, '\n');
		*tmp = ft_strchr(*tmp, '\n') + 1;
		*tmp = ft_strdup(*tmp);
		free(old);
	}
	else
	{
		*line = ft_strdup(*tmp);
		ft_strclr(*tmp);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tmp[10000];
	char		*old;
	char		*buff;
	int			new;

	if (BUFF_SIZE < 1 || !(buff = (char *)malloc(sizeof(buff) * BUFF_SIZE + 1)))
		return (-1);
	while ((new = read(fd, buff, BUFF_SIZE)))
	{
		if (new == -1 || new == 0)
			return (-1);
		buff[new] = '\0';
		if (tmp[fd] == NULL)
			tmp[fd] = ft_strdup(buff);
		else
		{
			old = tmp[fd];
			tmp[fd] = ft_strjoin(tmp[fd], buff);
			free(old);
		}
		if (ft_strchr(buff, '\n') != NULL)
			break ;
	}
	free(buff);
	return (ft_ret(line, &tmp[fd], new));
}

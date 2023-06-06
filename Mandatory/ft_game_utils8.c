/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:39 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 08:46:21 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

void	ft_ismapsquare5(char *line, int x)
{
	while (line[x] && line[x] != '\n')
	{
		if (line[x++] != '1')
		{
			free(line);
			ft_putstr("Error : Map is not square wall");
			exit(0);
		}
	}
}

void	ft_ismapsquare4(char *line, int x)
{
	if (x == 0 && line[x] != '1')
	{
		free(line);
		ft_putstr("Error : Map is not square wall");
		exit(0);
	}
	while (line[x] && line[x] != '\n')
	{
		if ((line[x + 1] == '\0' || \
		line[x + 1] == '\n') && line[x] != '1')
		{
			free(line);
			ft_putstr("Error : Map is not square wall");
			exit(0);
		}
		x++;
	}
}

void	ft_isvalidpath(char *str)
{
	int	i;

	i = open(str, O_RDWR);
	if (i == -1)
	{
		ft_putstr("Error : There is no file in path");
		exit(0);
	}
	close(i);
}

int	ft_maplen(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
		if (str[i++] != '\n')
			ret++;
	return (ret);
}

void	ft_isvaluesmore(char *str, t_counts *count)
{
	count->c = 0;
	count->p = 0;
	count->e = 0;
	count->w = 0;
	count->i = 0;
	count->fd = open(str, O_RDWR);
	str = get_next_line(count->fd);
	while (str)
	{
		while (str[count->i])
		{
			if (str[count->i] == 'C')
				count->c++;
			if (str[count->i] == 'W')
				count->w++;
			if (str[count->i] == 'E')
				count->e++;
			if (str[count->i++] == 'P')
				count->p++;
		}
		count->i = 0;
		free(str);
		str = get_next_line(count->fd);
	}
	ft_isvaluesmore2(count->c, count->p, count->e, count->w);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:39 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 23:40:20 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

void	ft_ismapsquare3(char *str, int endline)
{
	int		x;
	int		i;
	int		fd;
	char	*line;

	i = 0;
	x = 0;
	fd = open(str, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		if (i == 0 || i == endline - 1)
		{
			ft_ismapsquare5(line, x);
		}
		else
		{
			ft_ismapsquare4(line, x);
		}
		x = 0;
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	ft_ismapsquare2(char *str)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(str, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (count < 3)
	{
		ft_putstr("Error : Map is not square wall");
		close(fd);
		exit(0);
	}
	ft_ismapsquare3(str, count);
}

void	ft_ismapsquare(char *str)
{
	int		fd;
	char	*line;
	int		size;

	size = 0;
	fd = open(str, O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		if (!size)
			size = ft_maplen(line);
		if (size != ft_maplen(line))
		{
			free(line);
			ft_putstr("Error : Map is not square");
			close(fd);
			exit(0);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_ismapsquare2(str);
}

void	ft_isvalidmap2(char *str, char *str1, int i)
{
	int		fd;

	fd = open(str1, O_RDWR);
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] != 'E' && str[i] != '0' && \
			str[i] != '1' && \
			str[i] != 'P' && str[i] != '\n' && str[i] != 'C')
			{
				close(fd);
				ft_putstr("Error : Map Contains invalid characters");
				free(str);
				exit(0);
			}
			i++;
		}
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	ft_isvalidmap(char *str1)
{
	int		i;
	char	*str;

	str = "norm abi";
	i = 1;
	ft_isvalidmap2(str, str1, i);
}

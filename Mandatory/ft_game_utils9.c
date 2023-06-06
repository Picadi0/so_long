/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:39 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 13:59:53 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

void	ft_isvaluesmore2(int c, int p, int e, int w)
{
	if (p != 1)
	{
		ft_putstr("Error : There should be one player");
		exit(0);
	}
	if (w > 1)
	{
		ft_putstr("Error : There should be one enemy");
		exit(0);
	}
	if (c == 0)
	{
		ft_putstr("Error : map does not contain collectable");
		exit(0);
	}
	if (e != 1)
	{
		ft_putstr("Error : There should be one exit");
		exit(0);
	}
}

void	coin_reach(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				ft_putstr("Not reach the child");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	exit_reach(t_data *data)
{
	if (data->map[data->exity][data->exitx - 1] == '.')
		return ;
	if (data->map[data->exity - 1][data->exitx] == '.')
		return ;
	if (data->map[data->exity][data->exitx + 1] == '.')
		return ;
	if (data->map[data->exity + 1][data->exitx] == '.')
		return ;
	else
	{
		write(2, "not reach the exit\n", 19);
		exit(0);
	}
}

void	line(t_data *data, int y, int x)
{
	if (data->map[y][x + 1] == '0' || data->map[y][x + 1] == 'C'
		|| data->map[y][x + 1] == 'P' || data->map[y][x + 1] == 'E')
	{
		data->map[y][x + 1] = '.';
		line(data, y, x + 1);
	}
	if (data->map[y][x - 1] == '0' || data->map[y][x - 1] == 'C'
		|| data->map[y][x - 1] == 'P' || data->map[y][x - 1] == 'E')
	{
		data->map[y][x - 1] = '.';
		line(data, y, x - 1);
	}
	if (data->map[y + 1][x] == '0' || data->map[y + 1][x] == 'C'
		|| data->map[y + 1][x] == 'P' || data->map[y + 1][x] == 'E')
	{
		data->map[y + 1][x] = '.';
		line(data, y + 1, x);
	}
	if (data->map[y - 1][x] == '0' || data->map[y - 1][x] == 'C'
		|| data->map[y - 1][x] == 'P' || data->map[y - 1][x] == 'E')
	{
		data->map[y - 1][x] = '.';
		line(data, y - 1, x);
	}
}

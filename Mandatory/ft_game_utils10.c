/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:39 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 18:28:16 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

int	ft_closewin(t_data *data)
{
	t_data	*a;

	a = data;
	exit(0);
	return (0);
}

void	ft_is_enemy_touchme(t_data *data)
{
	if (data->p_position_x == data->enemy_position_x \
	&& data->p_position_y == data->enemy_position_y)
	{
		write(1, "your soul has been taken by purple guy\n", 39);
		exit(0);
	}
}

void	ft_loop_enemy_stuck(t_data *data)
{
	static int	i = 0;

	if (!i)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[0], data->enemy_position_x, data->enemy_position_y);
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[23], data->enemy_position_x, data->enemy_position_y);
		i = !i;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[0], data->enemy_position_x, data->enemy_position_y);
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[24], data->enemy_position_x, data->enemy_position_y);
		i = !i;
	}
}

void	player_location(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'E')
			{
				data->exitx = j;
				data->exity = i;
			}
			if (data->map[i][j] == 'P')
			{
				data->p_position_x = j;
				data->p_position_y = i;
			}
			j++;
		}
		i++;
	}
	line(data, data->p_position_y, data->p_position_x);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		data->map[i] = 0;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:41 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 18:24:49 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

int	ft_is_collectable(t_data *data, int x, int y)
{
	int	i;

	i = 0;
	while (i < data->collectable_count)
	{
		if (x == data->collectable_position_x[i] && \
		y == data->collectable_position_y[i])
		{
			data->collectable_position_x[i] = 0;
			data->collectable_position_y[i] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_is_exit(t_data *data, int x, int y)
{
	x /= 64;
	y /= 64;
	if (data->collected_count >= data->collectable_count)
	{
		if (data->map[y][x] == 'E')
		{
			ft_putstr("You saved all childs c:");
			exit(0);
		}
	}
}

void	ft_key_event_2(int keycode, t_data *data)
{
	static int	anim1 = 0;
	static int	anim2 = 0;

	if (keycode == 53)
		exit(0);
	if (ft_is_collectable(data, data->p_position_x, data->p_position_y))
	{
		data->collected_count++;
		data->map[data->p_position_y / 64][data->p_position_x / 64] = '0';
		ft_get_direction(&anim1, &anim2, data);
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[0], data->p_position_x, data->p_position_y);
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[anim1], data->p_position_x, data->p_position_y);
	}
	ft_is_exit(data, data->p_position_x, data->p_position_y);
}

//down right up left
void	ft_get_image(t_data *data, void **img1, void **img2, int direction)
{
	if (direction == 0)
	{
		*img1 = data->img[11];
		*img2 = data->img[12];
	}
	if (direction == 1)
	{
		*img1 = data->img[5];
		*img2 = data->img[6];
	}
	if (direction == 2)
	{
		*img1 = data->img[9];
		*img2 = data->img[10];
	}
	if (direction == 3)
	{
		*img1 = data->img[7];
		*img2 = data->img[8];
	}
}

void	ft_move_player(t_data *data, int x, int y, int direction)
{
	static int	next = 0;
	static void	*img1 = 0;
	static void	*img2 = 0;

	data->count = 0;
	mlx_put_image_to_window(data->mlx, data->mlx_window, \
	data->img[0], data->p_position_x, data->p_position_y);
	if (data->map[data->p_position_y / 64] \
	[data->p_position_x / 64] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[13], data->p_position_x, data->p_position_y);
	data->p_position_x = x;
	data->p_position_y = y;
	ft_get_image(data, &img1, &img2, direction);
	if (!next)
		mlx_put_image_to_window(data->mlx, \
		data->mlx_window, img1, data->p_position_x, data->p_position_y);
	else
		mlx_put_image_to_window(data->mlx, \
		data->mlx_window, img2, data->p_position_x, data->p_position_y);
	next = !next;
}

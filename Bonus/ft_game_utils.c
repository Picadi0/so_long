/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:31:12 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 13:05:50 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

void	ft_check_enemy(t_data *data)
{
	if (data->enemy_position_x != 0)
	{
		ft_is_enemy_touchme(data);
		ft_loop_enemy(data);
	}
}

void	ft_loop_enemy_2(t_data *data, int next)
{
	data->enemy_direction = 1;
	if (ft_is_moveable(data, data->enemy_position_x -64, \
	data->enemy_position_y, 1))
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[0], data->enemy_position_x, data->enemy_position_y);
		data->enemy_position_x -= 64;
		if (!next)
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[25], \
			data->enemy_position_x, data->enemy_position_y);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[26], \
			data->enemy_position_x, data->enemy_position_y);
	}
	else
		data->enemy_direction = 0;
}

void	ft_loop_enemy(t_data *data)
{
	static int	next = 0;
	static int	count = 0;

	count++;
	if (count > 1000)
	{
		ft_loop_enemy_stuck(data);
		if (!data->enemy_direction && ft_is_moveable(data, \
		data->enemy_position_x + 64, data->enemy_position_y, 1))
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img[0], data->enemy_position_x, data->enemy_position_y);
			data->enemy_position_x += 64;
			if (!next)
				mlx_put_image_to_window(data->mlx, data->mlx_window, \
				data->img[27], data->enemy_position_x, data->enemy_position_y);
			else
				mlx_put_image_to_window(data->mlx, data->mlx_window, \
				data->img[28], data->enemy_position_x, data->enemy_position_y);
		}
		else
			ft_loop_enemy_2(data, next);
		next = !next;
		count = 0;
	}
}

void	ft_loop_stand2(t_data *data)
{
	if (data->map[data->p_position_y / 64] \
	[data->p_position_x / 64] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[13], data->p_position_x, data->p_position_y);
	}	
}

int	ft_loop_stand(t_data *data)
{
	static int	next = 0;
	static int	anim1 = 0;
	static int	anim2 = 0;

	ft_get_direction(&anim1, &anim2, data);
	ft_check_enemy(data);
	ft_loop_cry(data);
	ft_loop_box(data);
	data->count++;
	if (data->count > 3000)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[0], data->p_position_x, data->p_position_y);
		ft_loop_stand2(data);
		if (!next)
			mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img[anim1], data->p_position_x, data->p_position_y);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img[anim2], data->p_position_x, data->p_position_y);
		next = !next;
		data->count = 0;
	}
	return (0);
}

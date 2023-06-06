/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:43 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 17:58:41 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

void	ft_draw_map_4(t_data *data, char *str, int j, int i)
{
	if (str[j] == 'E')
	{
		data->exitx = j * 64;
		data->exity = i * 64;
		mlx_put_image_to_window(data->mlx, \
		data->mlx_window, data->img[0], j * 64, i * 64);
		mlx_put_image_to_window(data->mlx, \
		data->mlx_window, data->img[13], j * 64, i * 64);
	}
}

void	ft_draw_map_2(t_data *data, char *str, int j, int i)
{
	if (str[j] == 'C')
	{
		if (!data->first_loaded)
		{	
			mlx_put_image_to_window(data->mlx, \
			data->mlx_window, data->img[0], j * 64, i * 64);
			mlx_put_image_to_window(data->mlx, \
			data->mlx_window, data->img[3], j * 64, i * 64);
			data->collectable_position_x \
			[data->collectable_count] = j * 64;
			data->collectable_position_y \
			[data->collectable_count] = i * 64;
			data->collectable_count++;
		}
	}
}

void	ft_draw_map_3(t_data *data, char *str, int j, int i)
{
	if (str[j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
	data->img[0], j * 64, i * 64);
	if (str[j] == 'P')
	{	
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[0], j * 64, i * 64);
		if (!data->first_loaded)
		{
			data->p_position_x = j * 64;
			data->p_position_y = i * 64;
			mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img[2], data->p_position_x, data->p_position_y);
		}
	}
	if (str[j] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[1], j * 64, i * 64);
		if (!data->first_loaded)
		{
			data->wall_position_x[data->wall_count] = j * 64;
			data->wall_position_y[data->wall_count++] = i * 64;
		}
	}
}

void	ft_draw_map_1(t_data *data, char *str, int j, int i)
{
	if (str[j] == 'W' && !data->first_loaded)
	{
		mlx_put_image_to_window(data->mlx, \
		data->mlx_window, data->img[0], j * 64, i * 64);
		mlx_put_image_to_window(data->mlx, \
		data->mlx_window, data->img[23], j * 64, i * 64);
		data->enemy_position_x = j * 64;
		data->enemy_position_y = i * 64;
	}
}

void	ft_draw_map(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		str = data->map[i];
		while (str[j])
		{
			ft_draw_map_1(data, str, j, i);
			ft_draw_map_2(data, str, j, i);
			ft_draw_map_3(data, str, j, i);
			ft_draw_map_4(data, str, j, i);
			j++;
		}
		j = 0;
		i++;
	}
	data->first_loaded++;
}

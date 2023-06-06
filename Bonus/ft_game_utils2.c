/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:47 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 18:03:20 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

void	ft_loop_cry_2(t_data *data, int next, int i)
{
	int	x;
	int	y;

	x = data->collectable_position_x[i];
	y = data->collectable_position_y[i];
	if (!next)
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[3], x, y);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
		data->img[16], x, y);
}

int	ft_loop_cry(t_data *data)
{
	static int	next = 0;
	static int	count = 0;
	int			i;

	i = 0;
	count++;
	if (count > 3000)
	{
		while (i < data->collectable_count)
		{
			if (data->collectable_position_x[i] != 0 && \
			data->collectable_position_y[i] != 0)
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, \
				data->img[0], data->collectable_position_x[i], \
				data->collectable_position_y[i]);
				ft_loop_cry_2(data, next, i);
			}
			i++;
		}
		next = !next;
		count = 0;
	}
	return (0);
}

int	ft_loop_box(t_data *data)
{
	static int	next = 0;
	static int	count = 0;
	int			i;

	i = 0;
	if (data->collected_count >= data->collectable_count)
	{
		count++;
		if (count > 3000)
		{
			mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img[0], data->exitx, data->exity);
			if (!next)
				mlx_put_image_to_window(data->mlx, data->mlx_window, \
				data->img[13], data->exitx, data->exity);
			else
				mlx_put_image_to_window(data->mlx, data->mlx_window, \
				data->img[14], data->exitx, data->exity);
			next = !next;
			count = 0;
		}
	}
	return (0);
}

int	ft_is_moveable(t_data *data, int x, int y, int isenemy)
{
	char	*str;

	str = "norminette abi";
	if (isenemy && data->map[y / 64][x / 64] == 'E')
		return (0);
	if (data->map[y / 64][x / 64] == '1')
		return (0);
	if (!isenemy)
	{
		data->step++;
		str = ft_itoa(data->step);
		write(1, "Step : ", 7);
		write(1, str, sizeof(str) - 1);
		write(1, "\n", 1);
		free(str);
	}
	return (1);
}

//down right up left
void	ft_get_direction(int *anim1, int *anim2, t_data *data)
{
	if (data->direction == 0)
	{
		*anim1 = 11;
		*anim2 = 4;
	}
	if (data->direction == 1)
	{
		*anim1 = 5;
		*anim2 = 20;
	}
	if (data->direction == 2)
	{
		*anim1 = 9;
		*anim2 = 17;
	}
	if (data->direction == 3)
	{
		*anim1 = 7;
		*anim2 = 19;
	}
}

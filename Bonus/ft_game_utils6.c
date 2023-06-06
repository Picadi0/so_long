/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:39 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 11:21:48 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

int	set_my_direction(t_data *data, int direction)
{
	data->direction = direction;
	return (1);
}

void	ft_show_step(t_data *data)
{
	char		*str;

	str = ft_itoa(data->step);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1], 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_window, data->img[1], 64, 0);
	mlx_string_put(data->mlx, data->mlx_window, 0, 15, 888888, "Step :");
	mlx_string_put(data->mlx, data->mlx_window, 45, 15, 888888, str);
	free(str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	ft_endswithber(char *str)
{
	int		i;
	int		j;
	char	*keyword;

	keyword = ".ber";
	i = 0;
	j = 0;
	while (str[i])
		i++;
	i -= 4;
	if (i < 0)
	{
		ft_putstr("Error : You should enter the map's path");
		exit(0);
	}
	while (str[i])
	{
		if (str[i++] != keyword[j++])
		{
			ft_putstr("Error : Your map must be end's with .ber");
			exit(0);
		}
	}
}

void	ft_checkvalues(int ac, char **av, t_data *data)
{
	t_counts	*count;

	count = ft_calloc(sizeof(t_counts), 1);
	if (ac != 2)
	{
		ft_putstr("Error : You should enter the map's path");
		exit(0);
	}
	ft_isvalidpath(av[1]);
	ft_endswithber(av[1]);
	ft_isvalidmap(av[1]);
	ft_ismapsquare(av[1]);
	ft_isvaluesmore(av[1], count);
	data->map_name = av[1];
	ft_init_map(data);
	player_location(data);
	coin_reach(data);
	exit_reach(data);
	free_map(data);
	free(count);
}

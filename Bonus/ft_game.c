/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:01:05 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 18:29:22 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_game.h"

//right up down left
int	ft_key_event(int keycode, t_data *data)
{
	int	posx;
	int	posy;

	posx = data->p_position_x;
	posy = data->p_position_y;
	if (keycode == 2)
		if (set_my_direction(data, 1) && ft_is_moveable(data, \
		posx + 64, posy, 0))
			ft_move_player(data, posx + 64, posy, 1);
	if (keycode == 13)
		if (set_my_direction(data, 2) && ft_is_moveable(data, \
		posx, posy - 64, 0))
			ft_move_player(data, posx, posy - 64, 2);
	if (keycode == 1)
		if (set_my_direction(data, 0) && ft_is_moveable(data, \
		posx, posy + 64, 0))
			ft_move_player(data, posx, posy + 64, 0);
	if (keycode == 0)
		if (set_my_direction(data, 3) && ft_is_moveable(data, \
		posx - 64, posy, 0))
			ft_move_player(data, posx - 64, posy, 3);
	ft_key_event_2(keycode, data);
	return (0);
}

void	ft_get_resoluation(t_data *data)
{
	int		i;
	int		j;
	char	c;

	c = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		data->resolotiony++;
		i++;
	}
	while (data->map[0][j])
	{
		c = data->map[0][j];
		if (c == 'E' || c == '0' || c == '1' || \
		c == 'C' || c == 'P' || c == 'W')
			data->resolotionx++;
		j++;
	}
}

void	ft_init_map(t_data *data)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(data->map_name, O_RDWR);
	if (data->map)
		free(data->map);
	data->map = ft_calloc(sizeof(char *), 1000);
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (data->map[i] == 0)
			break ;
		i++;
	}
}

void	ft_init_image(t_data *data, int imgx, int imgy)
{
	data->img[3] = mlx_xpm_file_to_image(data->mlx, COIN1, &imgx, &imgy);
	data->img[4] = mlx_xpm_file_to_image(data->mlx, STAND2, &imgx, &imgy);
	data->img[5] = mlx_xpm_file_to_image(data->mlx, RIGHT1, &imgx, &imgy);
	data->img[6] = mlx_xpm_file_to_image(data->mlx, RIGHT2, &imgx, &imgy);
	data->img[7] = mlx_xpm_file_to_image(data->mlx, LEFT1, &imgx, &imgy);
	data->img[8] = mlx_xpm_file_to_image(data->mlx, LEFT2, &imgx, &imgy);
	data->img[9] = mlx_xpm_file_to_image(data->mlx, UP1, &imgx, &imgy);
	data->img[10] = mlx_xpm_file_to_image(data->mlx, UP2, &imgx, &imgy);
	data->img[11] = mlx_xpm_file_to_image(data->mlx, DOWN1, &imgx, &imgy);
	data->img[12] = mlx_xpm_file_to_image(data->mlx, DOWN2, &imgx, &imgy);
	data->img[13] = mlx_xpm_file_to_image(data->mlx, DOOR1, &imgx, &imgy);
	data->img[14] = mlx_xpm_file_to_image(data->mlx, DOOR2, &imgx, &imgy);
	data->img[15] = mlx_xpm_file_to_image(data->mlx, DOOR3, &imgx, &imgy);
	data->img[16] = mlx_xpm_file_to_image(data->mlx, COIN2, &imgx, &imgy);
	data->img[17] = mlx_xpm_file_to_image(data->mlx, USTAND, &imgx, &imgy);
	data->img[19] = mlx_xpm_file_to_image(data->mlx, LSTAND, &imgx, &imgy);
	data->img[20] = mlx_xpm_file_to_image(data->mlx, RSTAND, &imgx, &imgy);
	data->img[21] = mlx_xpm_file_to_image(data->mlx, EUP1, &imgx, &imgy);
	data->img[22] = mlx_xpm_file_to_image(data->mlx, EUP2, &imgx, &imgy);
	data->img[23] = mlx_xpm_file_to_image(data->mlx, EDOWN1, &imgx, &imgy);
	data->img[24] = mlx_xpm_file_to_image(data->mlx, EDOWN2, &imgx, &imgy);
	data->img[25] = mlx_xpm_file_to_image(data->mlx, ELEFT1, &imgx, &imgy);
	data->img[26] = mlx_xpm_file_to_image(data->mlx, ELEFT2, &imgx, &imgy);
	data->img[27] = mlx_xpm_file_to_image(data->mlx, ERIGHT1, &imgx, &imgy);
	data->img[28] = mlx_xpm_file_to_image(data->mlx, ERIGHT2, &imgx, &imgy);
}

int	main(int ac, char **av)
{
	t_data		*data;
	static int	imgx = 0;
	static int	imgy = 0;

	data = ft_calloc(sizeof(t_data), 1);
	data->mlx = mlx_init();
	data->img = ft_calloc(sizeof(void *), 29);
	ft_checkvalues(ac, av, data);
	ft_init_map(data);
	ft_get_resoluation(data);
	data->mlx_window = mlx_new_window(data->mlx, \
	data->resolotionx * 64, data->resolotiony * 64, "Fnaf");
	data->collectable_position_x = ft_calloc(sizeof(void *), 1000);
	data->collectable_position_y = ft_calloc(sizeof(void *), 1000);
	data->wall_position_x = ft_calloc(sizeof(void *), 1000);
	data->wall_position_y = ft_calloc(sizeof(void *), 1000);
	data->img[0] = mlx_xpm_file_to_image(data->mlx, GROUND, &imgx, &imgy);
	data->img[1] = mlx_xpm_file_to_image(data->mlx, BLOCK, &imgx, &imgy);
	data->img[2] = mlx_xpm_file_to_image(data->mlx, STAND1, &imgx, &imgy);
	ft_init_image(data, imgx, imgy);
	ft_draw_map(data);
	mlx_hook(data->mlx_window, 17, 0, ft_closewin, data);
	mlx_hook(data->mlx_window, 2, 1L << 0, ft_key_event, data);
	mlx_loop_hook(data->mlx, ft_loop_stand, data);
	mlx_loop(data->mlx);
}

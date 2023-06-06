/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:27:35 by maltun            #+#    #+#             */
/*   Updated: 2023/05/30 18:17:10 by maltun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GAME_H
# define FT_GAME_H

# define STAND1 "./sources/main_character/stand1.xpm"
# define STAND2 "./sources/main_character/stand2.xpm"
# define UP1 "./sources/main_character/up1.xpm"
# define UP2 "./sources/main_character/up2.xpm"
# define LEFT1 "./sources/main_character/left1.xpm"
# define LEFT2 "./sources/main_character/left2.xpm"
# define RIGHT1 "./sources/main_character/right1.xpm"
# define RIGHT2 "./sources/main_character/right2.xpm"
# define DOWN1 "./sources/main_character/down1.xpm"
# define DOWN2 "./sources/main_character/down2.xpm"
# define LSTAND "./sources/main_character/leftstand.xpm"
# define RSTAND "./sources/main_character/rightstand.xpm"
# define USTAND "./sources/main_character/upstand.xpm"
# define GROUND "./sources/world_objects/zero.xpm"
# define BLOCK "./sources/world_objects/one.xpm"
# define COIN1 "./sources/world_objects/coin1.xpm"
# define COIN2 "./sources/world_objects/coin2.xpm"
# define DOOR1 "./sources/world_objects/door1.xpm"
# define DOOR2 "./sources/world_objects/door2.xpm"
# define DOOR3 "./sources/world_objects/door3.xpm"
# define EUP1 "./sources/enemy_character/up1.xpm"
# define EUP2 "./sources/enmy_character/up2.xpm"
# define ELEFT1 "./sources/enemy_character/left1.xpm"
# define ELEFT2 "./sources/enemy_character/left2.xpm"
# define ERIGHT1 "./sources/enemy_character/right1.xpm"
# define ERIGHT2 "./sources/enemy_character/right2.xpm"
# define EDOWN1 "./sources/enemy_character/down1.xpm"
# define EDOWN2 "./sources/enemy_character/down2.xpm"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include "../gnl/get_next_line.h"

typedef struct s_counts
{
	int	fd;
	int	c;
	int	p;
	int	e;
	int	w;
	int	i;
}	t_counts;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	void		**img;
	int			p_position_x;
	int			p_position_y;
	int			*wall_position_x;
	int			*wall_position_y;
	int			*collectable_position_x;
	int			*collectable_position_y;
	int			collectable_count;
	int			wall_count;
	int			collected_count;
	char		**map;
	int			count;
	int			resolotionx;
	int			direction;
	int			resolotiony;
	int			exitx;
	int			exity;
	int			step;
	int			enemy_position_x;
	int			enemy_position_y;
	int			enemy_direction;
	int			first_loaded;
	char		*map_name;
}	t_data;

int		ft_loop_stand(t_data *data);
void	ft_isvalidpath(char *str);
void	ft_putstr(char *str);
void	ft_loop_enemy(t_data *data);
void	ft_is_enemy_touchme(t_data *data);
int		ft_is_moveable(t_data *data, int x, int y, int isenemy);
void	ft_get_direction(int *anim1, int *anim2, t_data *data);
int		ft_loop_cry(t_data *data);
int		ft_loop_box(t_data *data);
char	*ft_itoa(int n);
void	*ft_calloc(size_t count, size_t size);
void	ft_draw_map(t_data *data);
void	ft_move_player(t_data *data, int x, int y, int direction);
int		ft_key_event(int keycode, t_data *data);
void	ft_key_event_2(int keycode, t_data *data);
int		set_my_direction(t_data *data, int direction);
void	ft_checkvalues(int ac, char **av, t_data *data);
void	ft_isvalidmap(char *str1);
void	ft_ismapsquare(char *str1);
int		ft_maplen(char *str);
void	ft_isvalidpath(char *str);
void	ft_isvaluesmore(char *str, t_counts *count);
void	ft_ismapsquare3c(char **line, int x);
void	ft_ismapsquare3c2(char **line, int x);
void	ft_ismapsquare4(char *line, int x);
void	ft_ismapsquare5(char *line, int x);
void	ft_isvaluesmore2(int c, int p, int e, int w);
void	ft_loop_enemy_stuck(t_data *data);
void	coin_reach(t_data *data);
void	line(t_data *data, int y, int x);
void	exit_reach(t_data *data);
void	ft_init_map(t_data *data);
void	player_location(t_data *data);
void	line(t_data *data, int y, int x);
void	free_map(t_data *data);
void	ft_is_enemy_touchme(t_data *data);
int		ft_closewin(t_data *data);

#endif
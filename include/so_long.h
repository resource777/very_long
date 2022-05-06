/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:36:59 by jaewonki          #+#    #+#             */
/*   Updated: 2022/05/06 12:37:06 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> 
# include <fcntl.h>
# include "../lib/libft/include/libft.h"
# include "../lib/libgnl/include/get_next_line.h"
# include "../lib/libmlx/mlx.h"

# define X_EVENT_KEY_PRESS  2
# define X_EVENT_KEY_EXIT   17

# define KEY_ESC    53
# define KEY_W      13
# define KEY_S      1
# define KEY_A      0
# define KEY_D      2

# define PX   64

typedef struct s_flags
{
	int	sign;
	int	home;
	int	dino;
}	t_flags;

typedef struct s_imgs
{
	void	*snow;
	void	*wall;
	void	*sign;
	void	*home;
	void	*dino;
}	t_imgs;

typedef struct s_pos
{
	int	col;
	int	row;
}	t_pos;

typedef struct s_player
{
	int		move_cnt;
	int		item_cnt;
	t_pos	pos;
}	t_player;

typedef struct s_map
{
	char	**chunks;
	t_pos	size;
	t_flags	flags;
}	t_map;

typedef struct s_game{
	t_map		map;
	t_player	player;	
	t_imgs		imgs;
	void		*mlx;
	void		*win;
}	t_game;

void	error_exit(const char *msg);
int		close_exit(t_game *game);

void	init_game(t_game *game, const char *map_path);
void	init_map(t_game *game, const char *map_path);
void	init_player(t_game *game);
void	init_img(t_game *game);
void	init_mlx_win(t_game *game);

void	get_map_chunks(t_game *game, const char *map_path);
void	get_map_size(t_map *map);
void	*get_img(t_game *game, char *img_path);
void	get_player_pos(t_game *game);

void	draw_map(t_game *game);
void	draw_component(t_game *game, t_pos pos);
void	ft_put_img(t_game *game, void *img, t_pos img_pos);

int		key_press(int keycode, t_game *game);
void	move(t_game *game, const int transform[2]);
void	move_to_item(t_game *game, t_pos dir);
void	move_to_snow(t_game *game, t_pos dir);
void	move_to_home(t_game *game);

void	check_map_path(const char *map_path, const char *suffix);
void	check_rectangul(t_map *map);
void	check_surround(t_map *map);
void	check_components(t_map *map);

#endif

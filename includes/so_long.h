/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:13:30 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 19:05:56 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>

# define KEY_PRESS 2
# define DESTROY_NOTIFY 17

# define KEY_ESC 53
# define KEY_W   13
# define KEY_A   0
# define KEY_S   1
# define KEY_D   2

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct map_data
{
	t_list	*map;
	char	**map_arr;
	char	**map_c;
	int		width;
	int		hight;
	int		collectible_total;
	int		collectible_current;
	t_point	player;
	int		exit_flag;
	int		movements_num;
	int		covered_flag;
	int		is_e;
}	t_map_data;

typedef struct textures
{
	void	*wall;
	void	*player;
	void	*free_space;
	void	*exit;
	void	*collect;
}	t_textures;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image_info;

typedef struct mlx_data
{
	void			*connection;
	void			*window;
	t_map_data		m_data;
	t_textures		game;
	t_image_info	image;
}	t_mlx_data;

void	check_isempty(t_list *map);
void	check_wall(t_list *map);
void	check_width_hight(t_map_data *m_data);
void	free_list(t_list *head);
void	check_player(t_list *map);
void	check_exit(t_list *map);
void	check_for_valid_symbols(t_list *map);
int		check_file_name(char *name);
void	check_collectible(t_map_data *m_data);
void	check_path(t_map_data *m_data);
void	flood_fill(char **tab, t_point size, t_point begin);
void	free_arr(char **arr, int hight);
void	item_search(t_map_data *m_data, t_point *player, char item);
int		map_rendering(t_mlx_data *mlx);
void	put_image(t_mlx_data *mlx);
int		events(int keycode, t_mlx_data *mlx);
void	cleanup(t_mlx_data *mlx);
int		close_window(t_mlx_data *mlx);

#endif
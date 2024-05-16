/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:13:30 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/16 15:24:59 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct map_data {
	t_list	*map;
	char	**map_arr;
	char	**map_c;
	int		width;
	int		hight;
	int		collectible_total;
	int		collectible_current;
}	t_map_data;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:03:15 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/16 19:49:29 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	save_textures(t_mlx_data *mlx, t_textures *game)
{
	int			img_width;
	int			img_height;

	game->wall = mlx_xpm_file_to_image(mlx->connection,
			"./textures/wall.xpm", &img_width, &img_height);
	game->free_space = mlx_xpm_file_to_image(mlx->connection,
			"./textures/free_space.xpm", &img_width, &img_height);
	game->player = mlx_xpm_file_to_image(mlx->connection,
			"./textures/player.xpm", &img_width, &img_height);
	game->collect = mlx_xpm_file_to_image(mlx->connection,
			"./textures/collect.xpm", &img_width, &img_height);
	game->exit = mlx_xpm_file_to_image(mlx->connection,
			"./textures/exit.xpm", &img_width, &img_height);
	if (game->wall == NULL || game->free_space == NULL || game->player == NULL
		|| game->collect == NULL || game->exit == NULL)
		return (1);
	else
		return (0);
}

int	map_rendering(t_map_data *m_data)
{
	t_mlx_data	mlx;
	t_textures	game;

	mlx.connection = mlx_init();
	if (mlx.connection == NULL && save_textures(&mlx, &game) == 1)
		return (1);
}

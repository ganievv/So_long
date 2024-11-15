/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:03:15 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 18:15:48 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

static void	struct_init(t_mlx_data *mlx)
{
	mlx->m_data.exit_flag = 0;
	mlx->m_data.movements_num = 0;
	mlx->m_data.covered_flag = 0;
	mlx->m_data.is_e = 0;
	mlx->game.wall = NULL;
	mlx->game.player = NULL;
	mlx->game.free_space = NULL;
	mlx->game.exit = NULL;
	mlx->game.collect = NULL;
	mlx->connection = NULL;
	mlx->window = NULL;
	mlx->image.img = NULL;
	mlx->image.addr = NULL;
}

int	map_rendering(t_mlx_data *mlx)
{
	struct_init(mlx);
	mlx->connection = mlx_init();
	if (mlx->connection == NULL)
		return (1);
	if (save_textures(mlx, &(mlx->game)) == 1)
		return (1);
	mlx->window = mlx_new_window(mlx->connection,
			mlx->m_data.width * 100, mlx->m_data.hight * 100, "Game");
	if (mlx->window == NULL)
		return (1);
	mlx->image.img = mlx_new_image(mlx->connection,
			mlx->m_data.width * 100, mlx->m_data.hight * 100);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
			&(mlx->image.bits_per_pixel),
			&(mlx->image.line_length), &(mlx->image.endian));
	if (mlx->image.img == NULL || mlx->image.addr == NULL)
		return (1);
	put_image(mlx);
	mlx_hook(mlx->window, DESTROY_NOTIFY, 0, close_window, mlx);
	mlx_hook(mlx->window, KEY_PRESS, 1L << 0, events, mlx);
	mlx_loop(mlx->connection);
	return (0);
}

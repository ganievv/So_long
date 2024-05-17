/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:03:15 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/17 17:37:08 by sganiev          ###   ########.fr       */
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

static void	image_put(char symb, t_mlx_data *mlx,
	t_textures *game, t_point *image)
{
	if (symb == '1')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			game->wall, image->x * 100, image->y * 100);
	if (symb == '0')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			game->free_space, image->x * 100, image->y * 100);
	if (symb == 'P')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			game->player, image->x * 100, image->y * 100);
	if (symb == 'C')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			game->collect, image->x * 100, image->y * 100);
	if (symb == 'E')
		mlx_put_image_to_window(mlx->connection, mlx->window,
			game->exit, image->x * 100, image->y * 100);
}

static void	put_image(t_mlx_data *mlx, t_textures *game, t_map_data *m_data)
{
	t_point			image;

	image.x = 0;
	image.y = 0;
	while (image.y < m_data->hight)
	{
		while (image.x < m_data->width)
		{
			image_put(m_data->map_c[image.y][image.x], mlx, game, &image);
			image.x++;
		}
		image.x = 0;
		image.y++;
	}
}

int	map_rendering(t_mlx_data *mlx)
{
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
	put_image(mlx, &(mlx->game), &(mlx->m_data));
	mlx_hook(mlx->window, 2, 1L << 0, events, mlx);
	mlx_loop(mlx->connection);
	mlx_destroy_window(mlx->connection, mlx->window);
	return (0);
}

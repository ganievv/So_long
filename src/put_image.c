/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:57:21 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/17 17:57:49 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	put_image(t_mlx_data *mlx)
{
	t_point			image;

	image.x = 0;
	image.y = 0;
	while (image.y < mlx->m_data.hight)
	{
		while (image.x < mlx->m_data.width)
		{
			image_put(mlx->m_data.map_c[image.y][image.x],
				mlx, &(mlx->game), &image);
			image.x++;
		}
		image.x = 0;
		image.y++;
	}
}

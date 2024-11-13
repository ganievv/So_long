/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:06:05 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 17:06:33 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	free_textures(t_mlx_data *mlx, t_textures *textures)
{
	if (textures->wall)
		mlx_destroy_image(mlx->connection, textures->wall);
	if (textures->free_space)
		mlx_destroy_image(mlx->connection, textures->free_space);
	if (textures->player)
		mlx_destroy_image(mlx->connection, textures->player);
	if (textures->collect)
		mlx_destroy_image(mlx->connection, textures->collect);
	if (textures->exit)
		mlx_destroy_image(mlx->connection, textures->exit);
}

void	cleanup(t_mlx_data *mlx)
{
	free_textures(mlx, &mlx->game);
	free_list(mlx->m_data.map);
	free_arr(mlx->m_data.map_arr, mlx->m_data.hight);
	free_arr(mlx->m_data.map_c, mlx->m_data.hight);
	if (mlx->image.img)
		mlx_destroy_image(mlx->connection, mlx->image.img);
	if (mlx->window)
		mlx_destroy_window(mlx->connection, mlx->window);
}

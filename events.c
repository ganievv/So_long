/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:36:48 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 15:44:56 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	events(int keycode, t_mlx_data *mlx)
{
	if (keycode == KEY_ESC)
		mlx_destroy_window(mlx->connection, mlx->window);
	if (keycode == KEY_W || keycode == KEY_A
		|| keycode == KEY_S || keycode == KEY_D)
	{
		old_place_check(&(mlx->m_data.covered_flag),
			mlx->m_data.map_c, mlx->m_data.player);
		code_check(keycode, &(mlx->m_data.player), mlx->m_data.map_c,
			&(mlx->m_data.movements_num));
		new_place_check(mlx->m_data.map_c, mlx->m_data.player, mlx);
		put_image(mlx);
		if (mlx->m_data.exit_flag == 1 && mlx->m_data.is_e == 1)
			display_win_message(mlx);
	}
	return (0);
}

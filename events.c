/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:36:48 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 17:19:00 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	display_win_message(t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = ((mlx->m_data.width * 100) / 2) - 125;
	y = (mlx->m_data.hight * 100) / 2;
	mlx_string_put(mlx->connection, mlx->window, x, y,
		0xFFFFFF, "Congratulations! You Win!");
}

static	void	code_check(int keycode, t_point *player, char **map, int *move)
{
	if (keycode == KEY_W && map[player->y - 1][player->x] != '1')
	{
		player->y--;
		(*move)++;
		ft_printf("Current number of movements: %d\n", *move);
	}
	else if (keycode == KEY_A && map[player->y][player->x - 1] != '1')
	{
		player->x--;
		(*move)++;
		ft_printf("Current number of movements: %d\n", *move);
	}
	else if (keycode == KEY_S && map[player->y + 1][player->x] != '1')
	{
		player->y++;
		(*move)++;
		ft_printf("Current number of movements: %d\n", *move);
	}
	else if (keycode == KEY_D && map[player->y][player->x + 1] != '1')
	{
		player->x++;
		(*move)++;
		ft_printf("Current number of movements: %d\n", *move);
	}
}

static	void	old_place_check(int *covered_flag, char **map, t_point old)
{
	if (*covered_flag == 1)
	{
		map[old.y][old.x] = 'E';
		*covered_flag = 0;
	}
	else
		map[old.y][old.x] = '0';
}

static	void	new_place_check(char **map, t_point new, t_mlx_data *mlx)
{
	if (map[new.y][new.x] == '0')
		map[new.y][new.x] = 'P';
	if (map[new.y][new.x] == 'C')
	{
		map[new.y][new.x] = 'P';
		mlx->m_data.collectible_current++;
		if (mlx->m_data.collectible_current == mlx->m_data.collectible_total)
			mlx->m_data.exit_flag = 1;
	}
	if (map[new.y][new.x] == 'E')
	{
		if (mlx->m_data.exit_flag == 1)
			mlx->m_data.is_e = 1;
		else
			mlx->m_data.covered_flag = 1;
		map[new.y][new.x] = 'P';
	}
}

int	events(int keycode, t_mlx_data *mlx)
{
	if (keycode == KEY_ESC)
	{
		cleanup(mlx);
		exit(0);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:24:22 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/16 15:24:52 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	item_search(t_map_data *m_data, t_point *player, char item)
{
	player->x = 0;
	player->y = 0;
	while (player->y < m_data->hight)
	{
		while (player->x < m_data->width)
		{
			if (m_data->map_arr[player->y][player->x] == item)
				return ;
			player->x++;
		}
		player->x = 0;
		player->y++;
	}
}

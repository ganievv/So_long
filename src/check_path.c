/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:53 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/28 14:58:38 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**to_array(t_map_data *m_data)
{
	char	**arr;
	t_list	*current;
	int		y;

	arr = (char **)malloc(sizeof(char *) * m_data->hight);
	if (arr == NULL)
		return (NULL);
	current = m_data->map;
	y = 0;
	while (current != NULL)
	{
		arr[y++] = ft_strdup(current->line);
		current = current->next;
	}
	return (arr);
}

static void	isinvalid(t_point *begin, t_map_data *m_data)
{
	if (begin->x == 0 && begin->y == 0)
	{
		ft_printf("Error\n!!!The player can't reach every item!!!\n");
		free_list(m_data->map);
		free_arr(m_data->map_arr, m_data->hight);
		exit(1);
	}
}

static void	check_flood(t_map_data *m_data)
{
	t_point	item;
	t_point	begin;

	item.x = 0;
	item.y = 0;
	while (item.y < m_data->hight)
	{
		while (item.x < m_data->width)
		{
			if (m_data->map_arr[item.y][item.x] == 'C'
				|| m_data->map_arr[item.y][item.x] == 'E')
			{
				begin.x = 0;
				begin.y = 0;
				isinvalid(&begin, m_data);
			}
			item.x++;
		}
		item.x = 0;
		item.y++;
	}
}

void	check_path(t_map_data *m_data)
{
	t_point	size;
	t_point	begin;

	m_data->map_arr = to_array(m_data);
	m_data->map_c = to_array(m_data);
	if (m_data->map_arr == NULL || m_data->map_c == NULL)
	{
		ft_printf("Error\n!!!Failed to accocate memory "
			"for a copy of the map!!!\n");
		free_list(m_data->map);
		free_arr(m_data->map_arr, m_data->hight);
		free_arr(m_data->map_c, m_data->hight);
		exit(1);
	}
	size.x = m_data->width;
	size.y = m_data->hight;
	item_search(m_data, &(m_data->player), 'P');
	begin.x = m_data->player.x;
	begin.y = m_data->player.y;
	flood_fill(m_data->map_arr, size, begin);
	check_flood(m_data);
}

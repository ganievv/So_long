/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_hight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:12:51 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 15:12:50 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// should you buf_w-- ? because in str there is \n

// ??? i < m_data->hight     OR      i <= m_data->hight   ???

void	check_width_hight(t_map_data *m_data)
{
	t_list	*current;
	int		line_size;

	m_data->hight = 0;
	current = m_data->map;
	while (current != NULL)
	{
		m_data->hight++;
		current = current->next;
	}
	current = m_data->map;
	line_size = ft_strlen(current->line);
	while (current != NULL)
	{
		if (ft_strlen(current->line) != line_size)
		{
			ft_printf("Error\n!!!The wall is crooked. Make it straight!!!\n");
			free_list(m_data->map);
			exit(1);
		}
		current = current->next;
	}
	m_data->width = line_size;
}

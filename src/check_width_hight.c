/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_hight.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:12:51 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/13 14:00:43 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	symb_count(char *line)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			break ;
		else
			size++;
		i++;
	}
	return (size);
}

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
	line_size = symb_count(current->line);
	while (current != NULL)
	{
		if (symb_count(current->line) != line_size)
		{
			ft_printf("Error\n!!!The wall is crooked. Make it straight!!!\n");
			free_list(m_data->map);
			exit(1);
		}
		current = current->next;
	}
	m_data->width = line_size;
}

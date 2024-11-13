/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:26 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/13 15:25:56 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(const char *line)
{
	int	collectible_count;
	int	i;

	collectible_count = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] == 'C')
			collectible_count++;
		i++;
	}
	return (collectible_count);
}

static void	end_program(t_list *map)
{
	ft_printf("Error\n!!!Incorrect number of collectibles\n");
	free_list(map);
	exit(1);
}

void	check_collectible(t_map_data *m_data)
{
	t_list	*current;

	current = m_data->map;
	m_data->collectible_current = 0;
	m_data->collectible_total = 0;
	while (current != NULL)
	{
		m_data->collectible_total += check_line(current->line);
		current = current->next;
	}
	if (m_data->collectible_total == 0)
		end_program(m_data->map);
}

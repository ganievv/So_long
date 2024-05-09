/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:48:26 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 17:51:28 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(const char *line)
{
	int	collectible_count;
	int	i;

	collectible_count = 0;
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'C')
			collectible_count++;
	}
	return (collectible_count);
}

static void	end_program(t_list *map)
{
	ft_printf("Error\n!!!Incorrect number of collectibles\n");
	free_list(map);
	exit(1);
}

void	check_collectible(t_list *map)
{
	int		collectible_count;
	t_list	*current;

	collectible_count = 0;
	current = map;
	while (current != NULL)
	{
		collectible_count += check_line(current->line);
		current = current->next;
	}
	if (collectible_count == 0)
		end_program(map);
}

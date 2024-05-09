/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:17:16 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 17:37:05 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ??? maybe you should add "&& line[i] != '\0'" in loop ???

// ??? should you save coordinates of player ???

static int	check_line(const char *line)
{
	int	player_count;
	int	i;

	player_count = 0;
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'P')
			player_count++;
	}
	return (player_count);
}

static void	end_program(t_list *map)
{
	ft_printf("Error\n!!!Incorrect number of players\n");
	free_list(map);
	exit(1);
}

void	check_player(t_list *map)
{
	int		player_count;
	t_list	*current;

	player_count = 0;
	current = map;
	while (current != NULL)
	{
		player_count += check_line(current->line);
		current = current->next;
	}
	if (player_count == 0 || player_count > 1)
		end_program(map);
}

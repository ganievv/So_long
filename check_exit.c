/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:42:15 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 17:44:46 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(const char *line)
{
	int	exit_count;
	int	i;

	exit_count = 0;
	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] == 'E')
			exit_count++;
	}
	return (exit_count);
}

static void	end_program(t_list *map)
{
	ft_printf("Error\n!!!Incorrect number of exits\n");
	free_list(map);
	exit(1);
}

void	check_exit(t_list *map)
{
	int		exit_count;
	t_list	*current;

	exit_count = 0;
	current = map;
	while (current != NULL)
	{
		exit_count += check_line(current->line);
		current = current->next;
	}
	if (exit_count == 0 || exit_count > 1)
		end_program(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_valid_symbols.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:55:10 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/11 18:38:39 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n')
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != 'C')
			return (1);
		i++;
	}
	return (0);
}

static void	end_program(t_list *map)
{
	ft_printf("Error\n!!!Incorrect symbols in the map\n");
	free_list(map);
	exit(1);
}

void	check_for_valid_symbols(t_list *map)
{
	t_list	*current;
	int		flag;

	current = map;
	flag = 0;
	while (current != NULL)
	{
		flag = check_line(current->line);
		if (flag == 1)
			end_program(map);
		current = current->next;
	}
}

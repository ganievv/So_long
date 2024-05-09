/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:31:07 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 16:36:36 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	first_line(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static void	check_flag(int flag, t_list *map)
{
	if (flag == 1)
	{
		ft_printf("Error\n!!!The wall should consist of '1' characters!!!\n");
		free_list(map);
		exit(1);
	}
}

void	check_wall(t_list *map)
{
	t_list	*current;
	int		flag;

	flag = 0;
	current = map;
	flag = first_line(current->line);
	check_flag(flag, map);
	while (current != NULL)
	{
		if (current->next == NULL)
			break ;
		current = current->next;
		flag = between_line(current->line);
		check_flag(flag, map);
	}
	flag = last_line(current->line);
	check_flag(flag, map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:31:07 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/13 14:11:50 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	bottom_top_lines(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
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

static int	between_line(const char *str)
{
	int	i;

	i = 0;
	if (str[i] != '1')
		return (1);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[--i] != '1')
		return (1);
	return (0);
}

void	check_wall(t_list *map)
{
	t_list	*current;
	int		flag;

	flag = 0;
	current = map;
	flag = bottom_top_lines(current->line);
	check_flag(flag, map);
	while (current != NULL)
	{
		if (current->next == NULL)
			break ;
		current = current->next;
		flag = between_line(current->line);
		check_flag(flag, map);
	}
	flag = bottom_top_lines(current->line);
	check_flag(flag, map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_isempty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:07:45 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 14:13:57 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_isempty(t_list *map)
{
	if (map == NULL)
	{
		ft_printf("Error\n!!!Map file is empty!!!\n");
		exit(1);
	}
}

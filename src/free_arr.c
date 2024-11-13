/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:19:27 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 17:12:30 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr, int hight)
{
	int	i;

	i = 0;
	while (i < hight)
	{
		if (arr[i])
			free(arr[i++]);
	}
	if (arr)
		free(arr);
}

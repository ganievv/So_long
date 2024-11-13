/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:14:16 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/28 15:10:08 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **tab, t_point size, t_point begin)
{
	t_point	up;
	t_point	down;
	t_point	left;
	t_point	right;

	if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
		return ;
	if (tab[begin.y][begin.x] == '1' || tab[begin.y][begin.x] == 'F')
		return ;
	tab[begin.y][begin.x] = 'F';
	up.x = begin.x;
	up.y = begin.y - 1;
	down.x = begin.x;
	down.y = begin.y + 1;
	left.x = begin.x - 1;
	left.y = begin.y;
	right.x = begin.x + 1;
	right.y = begin.y;
	flood_fill(tab, size, up);
	flood_fill(tab, size, down);
	flood_fill(tab, size, left);
	flood_fill(tab, size, right);
}

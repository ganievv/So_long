/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:19:53 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/15 19:02:04 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

static void	flood_fill(char **tab, t_point size, t_point begin)
{
	t_point	up;
	t_point	down;
	t_point	left;
	t_point	right;

	if (begin.x < 0 || begin.x >= size.x || begin.y < 0
		|| begin.y >= size.y || tab[begin.y][begin.x] != '0')
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

static char	**to_array(t_map_data *m_data)
{
	char	**arr;
	t_list	*current;
	int		y;

	arr = (char **)malloc(sizeof(char *) * m_data->hight);
	if (arr == NULL)
		return (NULL);
	current = m_data->map;
	y = 0;
	while (current != NULL)
	{
		arr[y++] = ft_strdup(current->line);
		current = current->next;
	}
}

void	begin_search(t_map_data *m_data, char **arr, t_point *begin)
{
}

void	check_path(t_map_data *m_data)
{
	char	**arr_copy;
	t_point	size;
	t_point	begin;

	m_data->map_arr = to_array(m_data);
	arr_copy = to_array(m_data);
	if (m_data->map_arr == NULL || arr_copy)
	{
	}
	size.x = m_data->width;
	size.y = m_data->hight;
	begin_search(m_data, arr_copy, &begin);
	flood_fill(arr_copy, size, begin);
}

//void	fill(char **tab, t_point size, t_point begin)
//{
//	if (begin.y + 1 < size.y && tab[begin.x][begin.y + 1] == '0')
//		tab[begin.x][begin.y + 1] = 'F';
//	if (begin.x + 1 < size.x && tab[begin.x + 1][begin.y] == '0')
//		tab[begin.x + 1][begin.y] = 'F';
//	if (begin.y - 1 > 1 && tab[begin.x][begin.y - 1] == '0')
//		tab[begin.x][begin.y - 1] = 'F';
//	if (begin.x - 1 > 1 && tab[begin.x - 1][begin.y] == '0')
//		tab[begin.x - 1][begin.y] = 'F';
//}

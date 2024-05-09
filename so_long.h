/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:13:30 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 12:57:37 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}	t_list;

typedef struct map_data {
	t_list	*map;
	int		width;
	int		hight;
}	t_map_data;

void	check_width_hight(t_map_data *m_data);

#endif
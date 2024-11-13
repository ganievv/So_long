/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:36:49 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/11 19:50:06 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file_name(char *name)
{
	int	line_length;

	line_length = ft_strlen(name);
	if (line_length > 4 && (ft_strncmp(name + line_length - 4, ".ber", 4) == 0))
		return (0);
	else
		return (1);
}

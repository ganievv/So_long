/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:15:59 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 13:06:32 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(char *map)
{
	int			fd;
	t_map_data	m_data;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file");
		exit(1);
	}
	read_map(fd, &m_data);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error!!! You need to pass .ber file and nothing else\n");
		return (1);
	}
	else
		open_map(argv[1]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:15:59 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/18 17:36:43 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// you should use your own ft_printf !!!

// you should check comments in test_1.c file

static void	check_map(t_map_data *m_data)
{
	check_isempty(m_data->map);
	check_for_valid_symbols(m_data->map);
	check_width_hight(m_data);
	check_wall(m_data->map);
	check_player(m_data->map);
	check_exit(m_data->map);
	check_collectible(m_data);
	check_path(m_data);
}

static void	append_node(t_list **head, char *line, int fd)
{
	t_list	*new_node;
	t_list	*current;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		ft_printf("Error\n!!!Failed to allocate node!!!\n");
		close(fd);
		exit(1);
	}
	new_node->line = line;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

static void	read_map(int fd, t_mlx_data	*mlx)
{
	char	*line;
	t_list	*head;

	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		append_node(&head, line, fd);
	}
	close(fd);
	mlx->m_data.map = head;
	check_map(&(mlx->m_data));
	if (map_rendering(mlx) == 1)
	{
		ft_printf("Error\n!!!Failed to render!!!\n");
		cleanup(mlx);
		exit(1);
	}
}

static void	open_map(char *map)
{
	int			fd;
	t_mlx_data	mlx;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n!!!Failed to open the file!!!\n");
		exit(1);
	}
	read_map(fd, &mlx);
}

int	main(int argc, char *argv[])
{
	int	flag;

	if (argc != 2)
	{
		ft_printf("Error\n!!!You need to pass a "
			".ber file and nothing else!!!\n");
		return (1);
	}
	else
	{
		flag = check_file_name(argv[1]);
		if (flag == 1)
		{
			ft_printf("Error\n!!!You should use a .ber file!!!\n");
			return (1);
		}
		open_map(argv[1]);
	}
	return (0);
}

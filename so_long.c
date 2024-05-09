/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:15:59 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/09 14:09:31 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// you should use your own ft_printf !!!

// you should check comments in test_1.c file

// you don't allocate memory for m_data->map, but only for strings
// maybe you should use strjoin but you own version? or maybe 
// you should usse just 1 string and strjoin? or fixed size buffer (e.g. 1000) ?

void	check_map(t_map_data *m_data)
{
	check_isempty(m_data->map);
	check_width_hight(m_data);
}

void	append_node(t_list **head, char *line)
{
	t_list	*new_node;
	t_list	*current;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
	{
		perror("Error\n!!!Failed to allocate node!!!\n");
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

void	read_map(int fd, t_map_data *m_data)
{
	char	*line;
	t_list	*head;

	head = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		append_node(&head, line);
	}
	m_data->map = head;
	check_map(m_data);
}

void	open_map(char *map)
{
	int			fd;
	t_map_data	m_data;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n!!!Failed to open file!!!\n");
		exit(1);
	}
	read_map(fd, &m_data);
	close(fd);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error\n!!!You need to pass .ber file and nothing else!!!\n");
		return (1);
	}
	else
		open_map(argv[1]);
	return (0);
}

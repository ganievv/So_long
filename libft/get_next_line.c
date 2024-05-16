/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:41:16 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/11 19:05:06 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*divide(char *buf_str, char **rest)
{
	char	*return_str;
	char	*new_l;
	int		i;
	int		y;

	i = 0;
	y = 0;
	new_l = ft_strchr(buf_str, '\n');
	if (new_l)
	{
		while (buf_str[i] != '\n')
			i++;
		return_str = (char *)ft_calloc(i + 2, sizeof(char));
		if (return_str == NULL)
			return (NULL);
		i = 0;
		while (buf_str[i] != '\n')
			return_str[y++] = buf_str[i++];
		return_str[y] = '\n';
		if (*(new_l + 1) != '\0')
			*rest = ft_strdup(new_l + 1);
		return (return_str);
	}
	else
		return (ft_strdup(buf_str));
}

static int	read_file(int fd, char **str)
{
	ssize_t	bytes;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (-1);
	while (!ft_strchr(*str, '\n'))
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && *str == NULL))
		{
			free(buf);
			return (-1);
		}
		buf[bytes] = '\0';
		tmp = *str;
		*str = ft_strjoin(*str, buf);
		free(tmp);
		if (bytes < BUFFER_SIZE)
			break ;
	}
	free(buf);
	return (0);
}

static void	free_str(char **str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char		*buf_str = NULL;
	char			*rest;
	char			*return_str;
	int				k;

	rest = NULL;
	return_str = NULL;
	k = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buf_str == NULL || (buf_str != NULL && !ft_strchr(buf_str, '\n')))
		k = read_file(fd, &buf_str);
	if (k == -1)
	{
		free_str(&buf_str);
		return (NULL);
	}
	return_str = divide(buf_str, &rest);
	free_str(&buf_str);
	if (rest != NULL)
	{
		buf_str = ft_strdup(rest);
		free_str(&rest);
	}
	return (return_str);
}

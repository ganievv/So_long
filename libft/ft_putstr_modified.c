/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_modified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:03:10 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:30:50 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_putstr_modified(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (write(fd, s, i));
}

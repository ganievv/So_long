/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:21:32 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:32:21 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_string(char *str, int *num_print)
{
	int		length;
	ssize_t	error;

	if (str)
	{
		length = ft_strlen(str);
		error = ft_putstr_modified(str, FD);
		(*num_print) += length;
	}
	else
	{
		error = ft_putstr_modified("(null)\0", FD);
		(*num_print) += 6;
	}
	return (error);
}

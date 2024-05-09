/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:03:00 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:32:04 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_other(char symb, int *num_print)
{
	ssize_t	error;

	error = ft_putchar_modified('%', FD);
	(*num_print)++;
	if (error == -1)
		return (-1);
	error = ft_putchar_modified(symb, FD);
	(*num_print)++;
	return (error);
}

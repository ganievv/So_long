/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:58:37 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:32:08 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_percent(int *num_print)
{
	ssize_t	error;

	error = ft_putchar_modified('%', FD);
	(*num_print)++;
	return (error);
}

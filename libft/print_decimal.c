/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:10:06 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:31:44 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_decimal(int num, int *num_print)
{
	char	*str_num;
	ssize_t	error;

	str_num = ft_itoa(num);
	if (str_num == NULL)
		return (-1);
	error = print_string(str_num, num_print);
	free(str_num);
	return (error);
}

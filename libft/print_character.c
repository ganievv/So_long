/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_character.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:38:58 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:31:39 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	print_character(int symb, int *num_print)
{
	char	buf_symb;
	ssize_t	error;

	buf_symb = symb;
	error = ft_putchar_modified(buf_symb, FD);
	(*num_print)++;
	return (error);
}

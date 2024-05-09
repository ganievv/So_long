/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsig_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:26:41 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:32:31 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	symb_caunt(unsigned int n)
{
	unsigned int	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	fill_str(unsigned int n, char *number, unsigned int size)
{
	number[size] = '\0';
	if (n == 0)
		number[0] = '0';
	while (n > 0)
	{
		number[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
}

static char	*unsigned_itoa(unsigned int n)
{
	char			*number;
	unsigned int	size;

	size = symb_caunt(n);
	number = (char *)malloc((size + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	fill_str(n, number, size);
	return (number);
}

ssize_t	print_unsig_decimal(unsigned int num, int *num_print)
{
	char	*str_num;
	ssize_t	error;

	str_num = unsigned_itoa(num);
	if (str_num == NULL)
		return (-1);
	error = print_string(str_num, num_print);
	free(str_num);
	return (error);
}

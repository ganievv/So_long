/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:35:38 by sganiev           #+#    #+#             */
/*   Updated: 2024/04/08 21:58:01 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	symb_caunt(long n, unsigned int minus_flag)
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
	if (minus_flag == 1)
		size++;
	return (size);
}

static void	fill_str(long n, char *number,
unsigned int size, unsigned int minus_flag)
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
	if (minus_flag == 1)
		number[size - 1] = '-';
}

char	*ft_itoa(int n)
{
	char			*number;
	unsigned int	minus_flag;
	unsigned int	size;
	long			buf_n;

	buf_n = (long)n;
	minus_flag = 0;
	if (buf_n < 0)
	{
		buf_n = buf_n * (-1);
		minus_flag = 1;
	}
	size = symb_caunt(buf_n, minus_flag);
	number = (char *)malloc((size + 1) * sizeof(char));
	if (number == NULL)
		return (NULL);
	fill_str(buf_n, number, size, minus_flag);
	return (number);
}

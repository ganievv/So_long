/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:46:40 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/12 13:46:11 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	symb_caunt(int n, unsigned int minus_flag)
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

static void	fill_str(int n, char *number, unsigned int minus_flag)
{
	int	size;
	int	i;

	i = 0;
	size = symb_caunt(n, minus_flag);
	number[size] = '\0';
	while (n > 0)
	{
		number[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	if (minus_flag == 1)
		number[size - 1] = '-';
}

static void	numb_to_str(int n, char *number)
{
	unsigned int	minus_flag;

	minus_flag = 0;
	if (n < 0)
	{
		n = n * (-1);
		minus_flag = 1;
	}
	fill_str(n, number, minus_flag);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	number[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		ft_memcpy(number, "-2147483648\0", 12);
	else if (n == 0)
	{
		number[0] = '0';
		number[1] = '\0';
	}
	else
		numb_to_str(n, number);
	while (number[i] != '\0')
	{
		i++;
	}
	write(fd, number, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:10:34 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:31:55 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_length(unsigned int buf_num)
{
	int		symb_count;

	symb_count = 0;
	if (buf_num == 0)
		return (1);
	while (buf_num > 0)
	{
		buf_num /= 16;
		symb_count++;
	}
	return (symb_count);
}

static void	choose_size(int low, char *hex_array)
{
	if (low == 1)
		ft_memcpy(hex_array, "0123456789abcdef\0", 17);
	else if (low == 0)
		ft_memcpy(hex_array, "0123456789ABCDEF\0", 17);
}

static void	fill_hex_array(unsigned int num, char *hex_low, char *hex_array)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		hex_low[i++] = hex_array[num % 16];
		num /= 16;
	}
}

ssize_t	print_hexadec(unsigned int num, int *num_print, int low)
{
	char	hex_array[17];
	char	*hex_low;
	int		symb_count;
	ssize_t	error;

	error = 0;
	choose_size(low, hex_array);
	symb_count = count_length(num);
	hex_low = (char *)ft_calloc((symb_count + 1), sizeof(char));
	if (hex_low == NULL)
		return (-1);
	if (num == 0)
		hex_low[0] = '0';
	fill_hex_array(num, hex_low, hex_array);
	while (symb_count > 0)
	{
		error = ft_putchar_modified(hex_low[symb_count-- - 1], FD);
		if (error == -1)
			break ;
		(*num_print)++;
	}
	free(hex_low);
	return (error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:53:13 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 14:30:11 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	type_search_print_arg(char symb, va_list arg_list,
int *num_print)
{
	ssize_t	error;

	error = 0;
	if (symb == 'c')
		error = print_character(va_arg(arg_list, int), num_print);
	else if (symb == 's')
		error = print_string(va_arg(arg_list, char *), num_print);
	else if (symb == 'p')
		error = print_pointer(va_arg(arg_list, void *), num_print);
	else if (symb == 'd' || symb == 'i')
		error = print_decimal(va_arg(arg_list, int), num_print);
	else if (symb == 'u')
		error = print_unsig_decimal(va_arg(arg_list, unsigned int), num_print);
	else if (symb == 'x')
		error = print_hexadec(va_arg(arg_list, unsigned int), num_print, 1);
	else if (symb == 'X')
		error = print_hexadec(va_arg(arg_list, unsigned int), num_print, 0);
	else if (symb == '%')
		error = print_percent(num_print);
	else
		error = print_other(symb, num_print);
	return (error);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int		i;
	int		num_print;
	ssize_t	error;

	va_start(arg_list, format);
	i = 0;
	num_print = 0;
	error = 0;
	while (format[i] && error != -1)
	{
		if (format[i] == '%')
			error = type_search_print_arg(format[++i], arg_list, &num_print);
		else
		{
			error = ft_putchar_modified(format[i], FD);
			num_print++;
		}
		i++;
	}
	va_end(arg_list);
	if (error == -1)
		return (-1);
	return (num_print);
}

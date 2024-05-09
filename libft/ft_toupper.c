/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:30:01 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/10 14:55:42 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int				upsymb;
	unsigned char	symb;

	symb = (unsigned char)c;
	if (symb >= 'a' && symb <= 'z')
	{
		upsymb = symb - ('a' - 'A');
		return (upsymb);
	}
	return (c);
}

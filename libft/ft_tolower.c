/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:29:21 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/10 14:55:37 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	int				upsymb;
	unsigned char	symb;

	symb = (unsigned char)c;
	if (symb >= 'A' && symb <= 'Z')
	{
		upsymb = symb + ('a' - 'A');
		return (upsymb);
	}
	return (c);
}

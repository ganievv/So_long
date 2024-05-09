/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:16:32 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/10 14:06:37 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	int				i;

	i = 0;
	value = (unsigned char)c;
	while (len > 0)
	{
		((unsigned char *)b)[i] = value;
		len--;
		i++;
	}
	return (b);
}

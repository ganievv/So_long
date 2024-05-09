/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:13:07 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/10 14:53:40 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sptr;
	unsigned char	symb;

	sptr = (unsigned char *)s;
	symb = (unsigned char)c;
	while (n > 0)
	{
		if (*sptr == symb)
		{
			return ((void *)sptr);
		}
		sptr++;
		n--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:21:29 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 13:35:05 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cptr;
	char	symb;

	if (s == NULL)
		return (NULL);
	cptr = (char *)s;
	symb = (char)c;
	while (*cptr)
	{
		if (*cptr == symb)
			return (cptr);
		cptr++;
	}
	if (*cptr == '\0' && symb == '\0')
		return (cptr);
	return (NULL);
}

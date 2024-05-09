/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:27:57 by sganiev           #+#    #+#             */
/*   Updated: 2024/04/05 20:42:07 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cptr;
	char	*returnptr;
	char	symb;

	cptr = (char *)s;
	returnptr = NULL;
	symb = (char)c;
	while (*cptr)
	{
		if (*cptr == symb)
			returnptr = cptr;
		cptr++;
	}
	if (*cptr == '\0' && symb == '\0')
		return (cptr);
	return (returnptr);
}

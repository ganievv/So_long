/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:26:49 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/13 13:49:24 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		y;

	i = 0;
	y = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i + y] == needle[y]
			&& needle[y] != '\0' && (i + y) < len)
		{
			y++;
		}
		if (needle[y] == '\0')
			return ((char *)&haystack[i]);
		i++;
		y = 0;
	}
	return (NULL);
}

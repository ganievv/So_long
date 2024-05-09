/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:34:07 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/13 22:04:30 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	result = malloc(end - start + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, s1 + start, end - start);
	result[end - start] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:22:07 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/08 13:40:21 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_s1;
	int		i;

	i = 0;
	if (s1 == NULL || *s1 == '\0')
		return (NULL);
	while (s1[i])
		i++;
	new_s1 = (char *)ft_calloc((i + 1), sizeof(char));
	if (new_s1 == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_s1[i] = s1[i];
		i++;
	}
	return (new_s1);
}

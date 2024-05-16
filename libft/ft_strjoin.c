/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:23:02 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/11 19:08:41 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	s1_len;
	unsigned int	s2_len;
	int				i;
	int				j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	new_str = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (s1 != NULL && s1[i])
		new_str[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i])
		new_str[j++] = s2[i++];
	return (new_str);
}

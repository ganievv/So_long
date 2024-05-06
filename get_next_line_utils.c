/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:41:19 by sganiev           #+#    #+#             */
/*   Updated: 2024/05/06 18:12:44 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = '\0';
		i++;
	}
	return (ptr);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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

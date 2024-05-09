/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganiev <sganiev@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:46:57 by sganiev           #+#    #+#             */
/*   Updated: 2024/03/13 15:00:07 by sganiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *s_start, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s_start[i] != '\0')
	{
		if (s_start[i] != c && (s_start[i + 1] == c || s_start[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static void	fill_str(char **empt_s, char *s, char c, int max_words)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	y = 0;
	z = 0;
	while (y < max_words)
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			empt_s[y][z] = s[i];
			z++;
			i++;
		}
		empt_s[y][z] = '\0';
		z = 0;
		y++;
	}
	empt_s[y] = NULL;
}

static int	creat_empty_array(int i, char c, char *s_start, char **str_array)
{
	int	y;
	int	z;
	int	symb_count;

	y = 0;
	z = 0;
	while (y < i)
	{
		symb_count = 0;
		while (s_start[z] == c)
			z++;
		while (s_start[z] != c && s_start[z++] != '\0')
		{
			symb_count++;
		}
		str_array[y] = (char *)malloc((symb_count + 1) * sizeof(char));
		if (str_array[y] == NULL)
		{
			while (y-- > 0)
				free (str_array[y]);
			return (-1);
		}
		y++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char			**str_array;
	char			*s_start;
	int				i;

	s_start = (char *)s;
	i = count_words(s_start, c);
	str_array = (char **)malloc((i + 1) * sizeof(char *));
	if (str_array == NULL)
	{
		return (NULL);
	}
	if (i == 0)
	{
		str_array[0] = NULL;
		return (str_array);
	}
	if ((creat_empty_array(i, c, s_start, str_array)) == -1)
	{
		free(str_array);
		return (NULL);
	}
	fill_str(str_array, (char *)s, c, i);
	return (str_array);
}

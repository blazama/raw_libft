/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:59:40 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:59:51 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static size_t	count_strings(char const *s, char c)
{
	size_t	i;
	size_t	string;
	size_t	flag;

	i = 0;
	string = 0;
	flag = 0;
	while (s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			string++;
		}
		if (s[i] == c)
			flag = 0;
		i++;
	}
	return (string);
}

static size_t	count_chars(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s != 0 && *s != c)
	{
		s++;
		counter++;
	}
	return (counter);
}

static	char	**free_split(char **split, int n)
{
	while (n >= 0)
	{
		free(split[n]);
		n--;
	}
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_strings;
	size_t	s_len;
	size_t	n;
	char	**result;

	if (*s == '\0' || s == NULL)
		return ((char **)ft_calloc(sizeof(char *), 1));
	n_strings = count_strings(s, c);
	result = ft_calloc(sizeof(char *), n_strings + 1);
	if (!result)
		return (0);
	n = 0;
	while (n < n_strings)
	{
		while (*s == c)
			s++;
		s_len = count_chars(s, c) + 1;
		result[n] = ft_calloc(sizeof(char), s_len);
		if (!result[n])
			return (free_split(result, n));
		ft_strlcpy(result[n], s, s_len);
		s += s_len;
		n++;
	}
	return (result);
}
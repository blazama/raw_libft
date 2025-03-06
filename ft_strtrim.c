/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:56:19 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:56:27 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static int	check_char(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		skip_start;
	int		skip_end;
	char	*trimmed;

	skip_start = 0;
	skip_end = ft_strlen(s1) - 1;
	if (s1 == 0)
		return (NULL);
	if (set == 0)
		return (ft_strdup(s1));
	while (s1[skip_start] != 0 && check_char(s1[skip_start], set) == 1)
		skip_start++;
	while (check_char(s1[skip_end], set) == 1)
		skip_end--;
	if (skip_start > skip_end)
		return (ft_strdup(""));
	trimmed = ft_substr(s1, skip_start, skip_end - skip_start + 1);
	if (!trimmed)
		return (0);
	return (trimmed);
}
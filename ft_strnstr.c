/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:57:10 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:57:16 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == 0 || ft_strlen(needle) > n)
		return (0);
	while ((char)haystack[i] != '\0')
	{
		j = 0;
		while ((char)haystack[i + j] == (char)needle[j] && (i + j) < n)
		{
			if ((char)haystack[i + j] == '\0' && (char)needle[j] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		if ((char)needle[j] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
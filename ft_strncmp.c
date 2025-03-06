/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:57:32 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:57:38 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1copy;
	unsigned char	*s2copy;

	i = 0;
	s1copy = (unsigned char *)s1;
	s2copy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((s1copy[i] != '\0') && (i != n - 1))
	{
		if (s1copy[i] != s2copy[i])
			return (s1copy[i] - s2copy[i]);
		i++;
	}
	return (s1copy[i] - s2copy[i]);
}
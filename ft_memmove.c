/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:44:06 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:44:07 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dest);
	if (dest < src)
	{
		i = 0;
		while (n--)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i ++;
		}
	}
	else if (dest > src)
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}
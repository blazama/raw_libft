/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:56:45 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:56:47 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				len;
	unsigned char	*copy;

	copy = (unsigned char *)str;
	len = ft_strlen(str);
	while (len >= 0)
	{
		if (copy[len] == (unsigned char)c)
			return ((char *)copy + len);
		len--;
	}
	return (0);
}
/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:46:58 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 09:47:05 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen > size)
		return (srclen + size);
	dst += dstlen;
	size -= dstlen;
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (srclen + dstlen);
}
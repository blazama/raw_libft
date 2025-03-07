/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzapico <bzapico@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 10:02:45 by bzapico           #+#    #+#             */
/*   Updated: 2025/03/01 10:02:55 by bzapico          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

static int	count_str(long int n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		n *= -1;
		counter++;
	}
	while (n > 9)
	{
		n /= 10;
		counter++;
	}
	return (counter + 1);
}

static char	set_str(long int num)
{
	if (num > 0)
		return (num % 10 + '0');
	if (num == 0)
		return ('0');
	else
		return ((num * -1) % 10 + '0');
}

static char	*fill_str(long int num, int strl, char *str)
{	
	int	i;

	i = 0;
	if (num == 0)
	{
		str[i] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		i++;
	}
	while (strl > i)
	{
		str[strl - 1] = set_str(num);
		num /= 10;
		strl--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			strl;
	long int	num;
	char		*str;

	num = n;
	strl = count_str(num);
	str = (char *)ft_calloc(sizeof(char), strl + 1);
	if (!str)
		return (0);
	str = fill_str(num, strl, str);
	return (str);
}
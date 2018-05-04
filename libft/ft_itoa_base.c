/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschukin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:31:42 by aschukin          #+#    #+#             */
/*   Updated: 2018/04/09 16:02:59 by aschukin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_base(long long num, int base)
{
	int		i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(long long num, int base)
{
	char	*str;
	int		count;
	int		i;

	count = ft_count_base(num, base);
	if (!(str = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	i = count - 1;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		if ((num % base) <= 9)
			str[i] = (num % base) + '0';
		else
			str[i] = (num % base) + 'A' - 10;
		num = num / base;
		i--;
	}
	return (str);
}

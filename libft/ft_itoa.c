/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:46:08 by mkurkar           #+#    #+#             */
/*   Updated: 2024/08/29 18:03:28 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_get_digits_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_build_str(int n, int len, int sign)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	str[i] = n + '0';
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	len = 1;
	sign = 0;
	if (n == -2147483648LL)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	len = ft_get_digits_len(n) + sign;
	str = ft_build_str(n, len, sign);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:33 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:56:27 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		j++;
	}
	j--;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

static unsigned long long	ft_itoa_calc(unsigned long long number, int base)
{
	int	num_digits;

	num_digits = 0;
	while (number != 0)
	{
		number /= base;
		num_digits++;
	}
	return (num_digits);
}

static void	fill_string(char *str, long n, int base, int *i)
{
	const char	*hex;

	hex = "0123456789abcdef";
	while (n != 0)
	{
		str[(*i)++] = hex[n % base];
		n /= base;
	}
}

char	*ft_signed_itoa_base(long n, int base)
{
	char	*str;
	int		i;
	int		is_negative;

	i = 0;
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	if (n == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (ft_itoa_calc(n, base) + is_negative
				+ 1));
	if (!str)
	{
		return (ft_strdup(""));
	}
	fill_string(str, n, base, &i);
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_itoa_base(void *n, int base, int type)
{
	char				*str;
	char				*hex;
	unsigned long long	number;
	int					i;

	hex = "0123456789abcdef";
	i = 0;
	if (type == 0)
		number = (unsigned int)(uintptr_t)n;
	else
		number = (unsigned long long)(uintptr_t)n;
	if (number == 0)
		return (ft_strdup("0"));
	str = (char *)malloc(sizeof(char) * (ft_itoa_calc(number, base) + 1));
	if (!str)
		return (ft_strdup(""));
	while (number != 0)
	{
		str[i++] = hex[number % base];
		number /= base;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

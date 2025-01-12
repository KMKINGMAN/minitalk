/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:59:10 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:56:19 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hex(char specifier, va_list args, t_flags *flag)
{
	int		count;
	char	*str;

	count = 0;
	if (specifier == 'x')
	{
		str = ft_itoa_base(va_arg(args, void *), 16, 0);
		if (flag->hash && str[0] != '0' && str)
			count += ft_putstr("0x");
		count += ft_putstr(str);
		free(str);
	}
	else if (specifier == 'X')
	{
		str = ft_itoa_base(va_arg(args, void *), 16, 0);
		if (flag->hash && str[0] != '0' && str)
			count += ft_putstr("0X");
		count += ft_putstr(ft_str_upper(str));
		free(str);
	}
	else if (specifier == 'p')
		count += handle_pointers(args);
	return (count);
}

int	handle_chars_and_strings(char specifier, va_list args)
{
	int		count;
	char	*str;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			count += ft_putstr("(null)");
		else
			count += ft_putstr(str);
	}
	else if (specifier == '%')
		count += ft_putchar('%');
	return (count);
}

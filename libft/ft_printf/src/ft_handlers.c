/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:50:34 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:56:12 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_signed_numbers(char specifier, va_list args, t_flags *flag)
{
	int		count;
	char	*str;
	int		n;

	count = 0;
	if (specifier == 'd' || specifier == 'i')
	{
		n = va_arg(args, int);
		if (flag->plus && n >= 0)
			count += ft_putchar('+');
		if (flag->space && n >= 0)
			count += ft_putchar(' ');
		str = ft_signed_itoa_base(n, 10);
		count += ft_putstr(str);
		free(str);
	}
	return (count);
}

int	handle_pointers(va_list args)
{
	int		count;
	char	*str;
	void	*ptr;

	count = 0;
	ptr = va_arg(args, void *);
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		str = ft_itoa_base(ptr, 16, 1);
		count += ft_putstr("0x");
		count += ft_putstr(str);
		free(str);
	}
	return (count);
}

static int	handle_unsigned_numbers(char specifier, va_list args, t_flags *flag)
{
	int		count;
	char	*str;

	count = 0;
	if (specifier == 'u')
	{
		str = ft_itoa_base(va_arg(args, void *), 10, 0);
		count += ft_putstr(str);
		free(str);
	}
	else if (specifier == 'x' || specifier == 'X' || specifier == 'p')
	{
		count += handle_hex(specifier, args, flag);
	}
	return (count);
}

int	process_format_specifier(const char *fmt, int *i, va_list args)
{
	t_flags	*flags;
	int		count;

	count = 0;
	if (fmt[*i] == '%')
	{
		(*i)++;
		flags = ft_parse_flag(fmt, i);
		if (fmt[*i] == '%' || fmt[*i] == 'c' || fmt[*i] == 's')
			count += handle_chars_and_strings(fmt[*i], args);
		else if (fmt[*i] == 'd' || fmt[*i] == 'i')
			count += handle_signed_numbers(fmt[*i], args, flags);
		else if (fmt[*i] == 'u' || fmt[*i] == 'x' || fmt[*i] == 'X'
			|| fmt[*i] == 'p')
			count += handle_unsigned_numbers(fmt[*i], args, flags);
		free(flags);
	}
	else
		count += ft_putchar(fmt[*i]);
	(*i)++;
	return (count);
}

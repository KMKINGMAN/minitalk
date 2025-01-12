/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:19:23 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:56:32 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*init_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	return (flags);
}

t_flags	*ft_parse_flag(const char *fmt, int *i)
{
	t_flags	*flags;

	flags = init_flags();
	while (fmt[*i] == '#' || fmt[*i] == ' ' || fmt[*i] == '+')
	{
		if (fmt[*i] == '#')
			flags->hash = 1;
		else if (fmt[*i] == ' ')
			flags->space = 1;
		else if (fmt[*i] == '+')
			flags->plus = 1;
		(*i)++;
	}
	return (flags);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:09:41 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:48:05 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_flags
{
	int	hash;
	int	space;
	int	plus;
}		t_flags;

char	*ft_itoa_base(void *n, int base, int type);
char	*ft_strrev(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_str_upper(char *str);
char	*ft_signed_itoa_base(long n, int base);
int		ft_printf(const char *fmt, ...);
t_flags	*init_flags(void);
t_flags	*ft_parse_flag(const char *fmt, int *i);
int		handle_chars_and_strings(char specifier, va_list args);
int		handle_hex(char specifier, va_list args, t_flags *flag);
int		process_format_specifier(const char *fmt, int *i, va_list args);
int		handle_pointers(va_list args);
#endif

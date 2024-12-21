/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonezero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:17:49 by mkurkar           #+#    #+#             */
/*   Updated: 2024/08/27 11:47:27 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_isalnum(int c)
{
	if (isalpha(c) || isdigit(c))
		return (8);
	return (0);
}

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

// int	main(void)
// {
// 	int i = 0;
// 	while (i < 256)
// 	{
// 		if (isalpha(i) != ft_isalpha(i))
// 		{
// 			printf("%i\t%i is alpha ", isalpha(i), ft_isalpha(i));
// 			printf("Error in ft_isalpha\n");
// 		}
// 		if (isdigit(i) != ft_isdigit(i))
// 		{
// 			printf("%i\t%i is isdigit ", isdigit(i), ft_isdigit(i));
// 			printf("Error in ft_isdigit\n");
// 		}
// 		if (isalnum(i) != ft_isalnum(i))
// 		{
// 			printf("%i\t%i is isalnum ", isalnum(i), ft_isalnum(i));
// 			printf("Error in ft_isalnum\n");
// 		}
// 		if (isascii(i) != ft_isascii(i))
// 		{
// 			printf("%i\t%i is isascii ", isascii(i), ft_isascii(i));
// 			printf("Error in ft_isascii\n");
// 		}
// 		if (isprint(i) != ft_isprint(i))
// 		{
// 			printf("%i\t%i is isprint ", isprint(i), ft_isprint(i));
// 			printf("Error in ft_isprint\n");
// 		}
// 		i++;
// 	}
// 	printf("All tests passed\n");
// 	return (0);
// }
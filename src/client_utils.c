/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:15:59 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 12:55:29 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_bool	ft_isdigit_string(char *data)
{
	int	i;

	i = 0;
	if (data == NULL)
		return (FALSE);
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_args_checker(int argc, char **argv)
{
	if (argc != 3 || !ft_isdigit_string(argv[1]) || argv[2] == NULL)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

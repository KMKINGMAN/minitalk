/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:15:59 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/21 11:53:55 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"

t_bool ft_isdigit_strint(char *data)
{
	int i;

	i = 0;
	if(data == NULL)
		return (FALSE);
	while (data[i])
	{
		if (!ft_isdigit(data[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void ft_args_checker(int argc, char **argv)
{
	if (argc != 3 || !ft_isdigit(*argv[1]) || argv[2] == NULL)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:16:36 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/21 11:53:40 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

#if BUFFER_SIZE < 1
# undef BUFFER_SIZE
# define BUFFER_SIZE 1000000
#endif

typedef enum e_bool
{
	FALSE,
	TRUE
} t_bool;

void	ft_args_checker(int argc, char **argv);

#endif

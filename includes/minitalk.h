/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:16:36 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/22 18:22:32 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

typedef enum e_bool
{
	FALSE,
	TRUE
}						t_bool;

typedef struct s_message
{
	char				*message;
	size_t				index;
	int					pid;
	size_t				buffer_size;
	struct s_message	*next;
	unsigned char		buff;
	int					bit_count;
	int					active;
}						t_message;

void					ft_args_checker(int argc, char **argv);
t_message				*init(int pid);
t_message				*search_or_create(t_message **head, int pid);
void					*remove_message(t_message **head, int pid);

#endif

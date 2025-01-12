/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:16:36 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:00:36 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "g_collector.h"

# define BUFFER_SIZE 1024
# define TRUE 1
# define FALSE 0

typedef struct s_message
{
    char            *message;
    unsigned char   buff;
    int            bit_count;
    size_t          index;
    size_t          buffer_size;
    int            active;
    int            pid;
    struct s_message *next;
}               t_message;

// Function prototypes
void    ft_args_checker(int argc, char **argv);
t_message *init(int pid);
t_message *search_or_create(t_message **head, int pid);
void    remove_message(t_message **head, int pid);

#endif

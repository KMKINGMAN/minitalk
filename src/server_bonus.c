/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:07:59 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:43:05 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_message(t_message **head, t_message **current,
		siginfo_t *siginfo)
{
	if (!(*current)->active)
		return ;
	if ((*current)->index == (*current)->buffer_size - 1)
	{
		(*current)->message = gc_realloc((*current)->message,
				(*current)->buffer_size + BUFFER_SIZE, (*current)->buffer_size);
		if (!(*current)->message)
			gc_finish_and_exit();
		ft_bzero((*current)->message + (*current)->buffer_size, BUFFER_SIZE);
		(*current)->buffer_size = (*current)->buffer_size + BUFFER_SIZE;
	}
	(*current)->message[(*current)->index] = (*current)->buff;
	(*current)->index = (*current)->index + 1;
	if ((*current)->buff == 0)
	{
		ft_printf("%s\n", (*current)->message);
		(*current)->active = 0;
		remove_message(head, siginfo->si_pid);
		(*current) = NULL;
		kill(siginfo->si_pid, SIGUSR1);
		return ;
	}
}

void	receive_message(int signal, siginfo_t *siginfo, void *context)
{
	static t_message	*head;
	t_message			*current;

	(void)context;
	if (head == NULL)
		head = init(siginfo->si_pid);
	current = search_or_create(&head, siginfo->si_pid);
	if (!current || !current->active)
		return ;
	if (signal == SIGUSR1)
		current->buff |= 1;
	current->bit_count++;
	if (current->bit_count == 8)
	{
		process_message(&head, &current, siginfo);
		if (current)
		{
			current->bit_count = 0;
			current->buff = 0;
		}
	}
	else
		current->buff = current->buff << 1;
	kill(siginfo->si_pid, SIGUSR1);
}

void	sig_handler(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &receive_message;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		(ft_printf("Error\n"));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(ft_printf("Error\n"));
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %i\n\n", pid);
	sig_handler();
	while (1)
		pause();
	return (0);
}

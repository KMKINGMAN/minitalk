/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:07:59 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/21 20:50:06 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/minitalk.h"
#include <signal.h>
#include <stdio.h>
#include "../gc_collector/g_collector.h"

int	g_received_bit = 0;


typedef struct s_message
{
	char	*message;
	size_t		index;
	int 	pid;
	size_t		buffer_size;
	struct s_message	*next;
	unsigned char		buff;
    int             bit_count;
    int             active;
}	t_message;


t_message *init(int pid)
{
	t_message *new;

	new = gc_malloc(sizeof(t_message));
	if (!new)
		return (NULL);
	new->message = gc_malloc(BUFFER_SIZE);
	if (!new->message)
		gc_finish_and_exit();
	ft_bzero(new->message, BUFFER_SIZE);
	new->index = 0;
	new->buffer_size = BUFFER_SIZE;
	new->pid = pid;
	new->buff = 0;
	new->next = NULL;
    new->bit_count = 0;
    new->active = 1;
	return (new);
}

t_message *search_or_create(t_message **head, int pid)
{
    t_message *current;
    t_message *new;

    if (!*head)
    {
        *head = init(pid);
        return (*head);
    }
    current = *head;
    while (current)
    {
        if (current->pid == pid)
            return (current);
        if (!current->next)
        {
            new = init(pid);
            current->next = new;
            return new;
        }
        current = current->next;
    }
    return (NULL);
}

void *remove_message(t_message **head, int pid)
{
	t_message	*current;
	t_message	*prev;

	if (!head || !*head)
		return (NULL);
	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->pid == pid)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			
			gc_free(current->message);
			gc_free(current);
			return (NULL);
		}
		prev = current;
		current = current->next;
	}
	return (NULL);
}

void process_message(t_message **head, t_message **current, siginfo_t *siginfo)
{
    if (!(*current)->active)
        return;
    if((*current)->index == (*current)->buffer_size - 1)
    {
        (*current)->message = gc_realloc((*current)->message, (*current)->buffer_size + BUFFER_SIZE, (*current)->buffer_size);
        if (!(*current)->message)
            gc_finish_and_exit();
        ft_bzero((*current)->message + (*current)->buffer_size, BUFFER_SIZE);
        (*current)->buffer_size = (*current)->buffer_size + BUFFER_SIZE;
    }
    (*current)->message[(*current)->index] = (*current)->buff;
    (*current)->index = (*current)->index + 1;
    if ((*current)->buff == 0)
    {
        (*current)->active = 0;
        printf("PID:%i\n", (*current)->pid);
        printf("Message:%li- %s\n", (*current)->index, (*current)->message);
        remove_message(head, siginfo->si_pid);
        (*current) = NULL;
        kill(siginfo->si_pid, SIGUSR1);
        return;
    }
}

void    receive_message(int signal, siginfo_t *siginfo, void *context)
{
    static t_message		*head;
    t_message				*current;

    (void)context;
    if(head == NULL)
        head = init(siginfo->si_pid);
    current = search_or_create(&head, siginfo->si_pid);
    if (!current || !current->active)
        return;
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
		(write(1, "Error\n", 6));
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		(write(1, "Error\n", 6));
}


int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %i\n\n", pid);
	sig_handler();
	while (1)
		pause();
	return (0);
}

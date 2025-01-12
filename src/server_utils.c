/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:03:25 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/12 18:42:55 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_message	*init(int pid)
{
	t_message	*new;

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

t_message	*search_or_create(t_message **head, int pid)
{
	t_message	*current;
	t_message	*new;

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
			return (new);
		}
		current = current->next;
	}
	return (NULL);
}

void	*remove_message(t_message **head, int pid)
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

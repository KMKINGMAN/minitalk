/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:39:02 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/21 15:00:44 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "g_collector.h"
#include <stdio.h>
#include <stdlib.h>

void			gc_finish(void) __attribute__((destructor));

void	gc_finish_and_exit(void)
{
	gc_finish();
	exit(EXIT_FAILURE);
}

t_memory_block	**gc_init(int status)
{
	static t_memory_block	*head;

	if (status == GC_RESTORE)
		head = NULL;
	return (&head);
}

void	*gc_malloc(size_t size)
{
	void			*ptr;
	t_memory_block	*block;

	ptr = malloc(size);
	if (!ptr)
		gc_finish_and_exit();
	block = (t_memory_block *)malloc(sizeof(t_memory_block));
	if (!block)
		gc_finish_and_exit();
	block->ptr = ptr;
	block->next = *gc_init(GC_GETDATA);
	*gc_init(0) = block;
	return (ptr);
}

void	gc_free(void *ptr)
{
	t_memory_block	**current;
	t_memory_block	*temp;
	

	current = gc_init(GC_GETDATA);
	while (*current)
	{
		if ((*current)->ptr == ptr)
		{
			temp = *current;
			*current = (*current)->next;
			free(temp->ptr);
			free(temp);
			return ;
		}
		current = &(*current)->next;
	}
}

void	gc_finish(void)
{
	t_memory_block	*temp;

	while (*gc_init(GC_GETDATA))
	{
		temp = *gc_init(GC_GETDATA);
		*gc_init(GC_GETDATA) = (*gc_init(GC_GETDATA))->next;
		free(temp->ptr);
		free(temp);
	}
}

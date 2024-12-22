/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:15:02 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/22 18:34:10 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_collector.h"

void	gc_add_pointer(void *ptr)
{
	t_memory_block	*block;

	block = (t_memory_block *)malloc(sizeof(t_memory_block));
	if (!block)
		gc_finish_and_exit();
	block->ptr = ptr;
	block->next = *gc_init(GC_GETDATA);
	*gc_init(0) = block;
}

void	*gc_remove_pointer(void *ptr)
{
	t_memory_block	**current;
	t_memory_block	*temp;
	void			*removed_ptr;

	current = gc_init(GC_GETDATA);
	while (*current)
	{
		if ((*current)->ptr == ptr)
		{
			temp = *current;
			*current = (*current)->next;
			removed_ptr = temp->ptr;
			free(temp);
			return (removed_ptr);
		}
		current = &(*current)->next;
	}
	return (NULL);
}

void	*gc_realloc(void *ptr, size_t size, size_t old_size)
{
	t_memory_block	**current;
	void			*new_ptr;

	current = gc_init(GC_GETDATA);
	while (*current)
	{
		if ((*current)->ptr == ptr)
		{
			new_ptr = ft_realloc(ptr, size, old_size);
			if (!new_ptr)
				gc_finish_and_exit();
			(*current)->ptr = new_ptr;
			return (new_ptr);
		}
		current = &(*current)->next;
	}
	return (NULL);
}

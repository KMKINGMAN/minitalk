/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:15:02 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/22 19:12:24 by mkurkar          ###   ########.fr       */
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

static void	*gc_memcpy(void *dst, const void *src, size_t size, size_t old_size)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dst || !src)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	i = 0;
	while (i < old_size && i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
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
			new_ptr = malloc(size);
			if (!new_ptr)
				gc_finish_and_exit();
			gc_memcpy(new_ptr, ptr, size, old_size);
			free(ptr);
			(*current)->ptr = new_ptr;
			return (new_ptr);
		}
		current = &(*current)->next;
	}
	return (NULL);
}

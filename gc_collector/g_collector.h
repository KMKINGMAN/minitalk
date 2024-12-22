/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_collector.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:39:08 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/22 19:14:47 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_COLLECTOR_H
# define G_COLLECTOR_H
# include <stddef.h>
# include <stdlib.h>

typedef struct s_memory_block
{
	void					*ptr;
	struct s_memory_block	*next;
	int						status;
}							t_memory_block;

typedef enum e_gc_status
{
	GC_GETDATA,
	GC_RESTORE
}							t_gc_status;

void						gc_finish_and_exit(void);
t_memory_block				**gc_init(int status);
void						*gc_malloc(size_t size);
void						gc_free(void *ptr);
void						gc_finish(void);
void						gc_add_pointer(void *ptr);
void						*gc_remove_pointer(void *ptr);
void						*gc_realloc(void *ptr, size_t size,
								size_t old_size);

#endif

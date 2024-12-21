/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 23:44:26 by mkurkar           #+#    #+#             */
/*   Updated: 2024/08/31 17:18:01 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *node, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*buf;
	void	*new_content;

	new = NULL;
	while (node)
	{
		new_content = f(node->content);
		buf = ft_lstnew(new_content);
		if (!buf)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, buf);
		node = node->next;
	}
	return (new);
}

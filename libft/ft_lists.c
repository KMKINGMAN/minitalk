/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:27:16 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/24 12:28:49 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

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

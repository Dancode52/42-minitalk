/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:49:15 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/08 18:35:28 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newptr;
	void	*i;

	newlst = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		i = f(lst->content);
		newptr = ft_lstnew(i);
		if (newptr == NULL)
		{
			del(i);
			ft_lstclear(&newlst, del);
			newlst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&newlst, newptr);
		lst = lst->next;
	}
	return (newlst);
}

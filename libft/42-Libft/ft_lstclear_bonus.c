/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:10:01 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/08 18:34:56 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = save;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:01:39 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/08 18:35:13 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst != NULL && new != NULL)
	{
		if (*lst != NULL)
		{
			ptr = ft_lstlast(*lst);
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

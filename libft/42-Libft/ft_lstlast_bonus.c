/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:32:21 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/08 18:35:25 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;
	int	end;

	if (!lst)
		return (NULL);
	i = 0;
	end = ft_lstsize(lst);
	while (i < end - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

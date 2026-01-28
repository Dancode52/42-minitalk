/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanehar <dlanehar@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:38:50 by dlanehar          #+#    #+#             */
/*   Updated: 2026/01/08 18:35:31 by dlanehar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nodetest;

	nodetest = malloc(sizeof(t_list));
	if (!nodetest)
		return (NULL);
	nodetest->content = content;
	nodetest->next = NULL;
	return (nodetest);
}

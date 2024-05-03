/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamatsuu <tamatsuu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:35:20 by tamatsuu          #+#    #+#             */
/*   Updated: 2024/05/03 14:03:36 by tamatsuu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list			*current;
	t_list			*prev;

	if (!lst || del)
		return ;
	current = *lst;
	while (current && current->next)
	{
		prev = current;
		current = current->next;
		prev->next = NULL;
		ft_lstdelone(prev, del);
	}
	free(lst);
}

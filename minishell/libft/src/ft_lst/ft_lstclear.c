/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:50:51 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:50:51 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_lst.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	void	*prev;

	if (!lst)
		return ;
	while (*lst)
	{
		if (del)
			del((*lst)->data);
		prev = *lst;
		*lst = (*lst)->next;
		free(prev);
	}
	*lst = NULL;
}

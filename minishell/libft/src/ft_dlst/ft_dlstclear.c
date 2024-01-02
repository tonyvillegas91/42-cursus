/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:28 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:49:28 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_dlst.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	void	*prev;

	if (!dlst || !del)
		return ;
	while (*dlst)
	{
		del((*dlst)->data);
		prev = *dlst;
		*dlst = (*dlst)->next;
		free(prev);
	}
	*dlst = NULL;
}

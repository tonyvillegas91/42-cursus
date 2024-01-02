/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:18 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:49:18 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_dlst.h"

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*last;

	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		last = ft_dlstlast(*dlst);
		last->next = new;
		new->prev = last;
	}
	else
		*dlst = new;
}

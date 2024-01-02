/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:23 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:49:23 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_dlst.h"

void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new)
{
	if (!dlst || !new)
		return ;
	if (*dlst)
	{
		new->next = *dlst;
		(*dlst)->prev = new;
		*dlst = new;
	}
	else
		*dlst = new;
}

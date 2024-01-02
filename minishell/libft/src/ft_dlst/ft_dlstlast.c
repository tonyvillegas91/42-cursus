/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:49:47 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:49:47 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_dlst.h"

t_dlist	*ft_dlstlast(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->next)
		dlst = dlst->next;
	return (dlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:41:59 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:41:59 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_dlst.h>

t_dlist	*ft_dlstfirst(t_dlist *dlst)
{
	if (!dlst)
		return (NULL);
	while (dlst->prev)
		dlst = dlst->prev;
	return (dlst);
}

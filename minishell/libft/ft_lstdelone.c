/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:29:31 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:29:31 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Takes as a parameter an element and frees the
** memory of the element’s content using the function’del’ 
** given as a parameter and free the element. The memory 
** of ’next’ must not be freed. */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL)
	{
		if (del != NULL && lst->content != NULL)
			(del)(lst->content);
		free(lst);
		lst = NULL;
	}
}

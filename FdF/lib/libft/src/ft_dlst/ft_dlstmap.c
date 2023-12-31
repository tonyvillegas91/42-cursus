/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:00:41 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:00:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <libft/ft_dlst.h>

t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist	*new;
	t_dlist	*newdlst;

	if (!dlst || !f)
		return (NULL);
	newdlst = NULL;
	while (dlst)
	{
		new = ft_dlstnew(f(dlst->data));
		if (!new)
		{
			ft_dlstclear(&newdlst, del);
			return (NULL);
		}
		ft_dlstadd_back(&newdlst, new);
		dlst = dlst->next;
	}
	return (newdlst);
}

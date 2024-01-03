/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:29:42 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:29:42 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Iterates the list ’lst’ and applies the 
** function’f’ to the content of each element */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	aux = lst;
	if (!lst || !f)
		return ;
	while (aux)
	{
		f(aux->content);
		aux = aux->next;
	}
}

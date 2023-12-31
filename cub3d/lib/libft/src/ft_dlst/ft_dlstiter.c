/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:42:03 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:42:03 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_dlst.h>

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	if (!dlst || !f)
		return ;
	while (dlst)
	{
		f(dlst->data);
		dlst = dlst->next;
	}
}

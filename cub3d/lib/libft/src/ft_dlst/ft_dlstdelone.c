/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:41:54 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:41:54 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_dlst.h>

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (!dlst || !del)
		return ;
	del(dlst->data);
	free(dlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:50:01 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:50:01 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_dlst.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	len;

	if (!dlst)
		return (0);
	len = 0;
	while (dlst && ++len)
		dlst = dlst->next;
	return (len);
}

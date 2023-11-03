/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:52:48 by antville          #+#    #+#             */
/*   Updated: 2021/04/22 16:37:01 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out->content = content;
	out->next = 0;
	return (out);
}
/*int		main(void)
{
	char	str[] = "lorem ipsum dolor sit";
	t_list	*elem;
	elem = ft_lstnew((void *)str);
	printf("\n%s\n", elem->content);
}*/

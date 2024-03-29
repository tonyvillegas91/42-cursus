/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 21:57:04 by antville          #+#    #+#             */
/*   Updated: 2021/09/29 19:05:26 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Checks if the stack passed as parameter is sorted */

int	is_sorted(t_list **a, int length)
{
	t_list	*aux;
	int		i;
	int		n1;
	int		n2;

	aux = *a;
	i = -1;
	while (++i < length - 1)
	{
		n1 = *(int *)aux->content;
		n2 = *(int *)aux->next->content;
		if (n1 > n2)
			return (0);
		aux = aux->next;
	}
	return (1);
}

/* Starts the push_swap, first it checks if the numbers are
already sorted, then simplifies the stack and calls small or big
depending on the size of the stack */

int	push_swap(t_list **a, t_list **b)
{
	int	length;

	length = ft_lstsize(*a);
	if (is_sorted(a, length))
		return (0);
	simplify_stack(a, b, length);
	if (length <= 5)
		sort_small_stack(a, b, length);
	else
		sort_big_stack(a, b, length);
	return (0);
}

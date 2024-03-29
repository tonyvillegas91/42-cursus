/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:04:34 by antville          #+#    #+#             */
/*   Updated: 2021/09/29 18:24:40 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Rotates the list passed as argument,  
shifts up all elements of stack a by 1. 
The first element becomes the last one. */

int	rotate(t_list **stack)
{
	t_list	*first;

	if (*stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	first = *stack;
	*stack = first->next;
	ft_lstlast(*stack)->next = first;
	first->next = NULL;
	return (1);
}

/* Calls rotate and executes ra, rb or rr 
depending on the char we passed as parameter
when we called it */

void	ft_rotate(t_list **a, t_list **b, char c)
{
	if (c == 'a')
	{
		if (rotate(a))
			write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		if (rotate(b))
			write(1, "rb\n", 3);
	}
	if (c == 'r')
	{
		if (rotate(a) && rotate(b))
			write(1, "rr\n", 3);
	}
}

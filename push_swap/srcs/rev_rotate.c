/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:11:49 by antville          #+#    #+#             */
/*   Updated: 2021/09/29 18:24:09 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* Iterates the list passed till the previous to last
value and returns it */

t_list	*ft_lstprev(t_list *stack)
{
	int	size;
	int	i;

	i = 1;
	size = ft_lstsize(stack);
	if (stack == NULL)
		return (NULL);
	while (i < size - 1)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

/*  Rotates the list passed as argument,
shifts down all elements of stack by 1. 
The last element becomes the first one. */

int	rev_rotate(t_list **stack)
{
	t_list	*prev;
	t_list	*first;

	if (*stack == NULL || ft_lstsize(*stack) < 2)
		return (0);
	first = *stack;
	prev = ft_lstprev(*stack);
	*stack = ft_lstlast(*stack);
	(*stack)->next = first;
	prev->next = NULL;
	return (1);
}

/* Calls rev_rotate and executes rra, rrb or rrr 
depending on the char we passed as parameter
when we called it */

void	ft_rev_rotate(t_list **a, t_list **b, char c)
{
	if (c == 'a')
	{
		if (rev_rotate(a))
			write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		if (rev_rotate(b))
			write(1, "rrb\n", 4);
	}
	if (c == 'r')
	{
		if (rev_rotate(a) && rev_rotate(b))
			write(1, "rrr\n", 4);
	}
}

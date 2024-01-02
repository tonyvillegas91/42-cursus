/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:57:33 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:57:33 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_printf.h"

static void	ft_handle_left_align(t_print *tab)
{
	tab->wd--;
	while (tab->wd-- > 0)
	{
		if (tab->zero)
			tab->tlen += (int)write(tab->d, "0", 1);
		else
			tab->tlen += (int)write(tab->d, " ", 1);
	}
}

static void	ft_handle_right_align(t_print *tab)
{
	tab->wd--;
	while (tab->wd-- > 0)
		tab->tlen += (int)write(tab->d, " ", 1);
}

void	ft_printf_char(t_print *tab)
{
	char	c;

	c = (char)va_arg(tab->args, int);
	if ((tab->zero || tab->wd) && !tab->dash)
		ft_handle_left_align(tab);
	tab->tlen += (int)write(tab->d, &c, 1);
	if (tab->wd && tab->dash)
		ft_handle_right_align(tab);
}

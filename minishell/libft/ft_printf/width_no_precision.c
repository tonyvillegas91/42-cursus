/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_no_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:27:45 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:27:45 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	basic_width(t_print *tab, char *str, long len)
{
	if (tab->dash)
	{
		tab->length += write(1, str, len);
		ft_fill_space(tab->width - len, tab);
	}
	else
	{
		ft_fill_space(tab->width - len, tab);
		tab->length += write(1, str, len);
	}
}

void	len_width_nopreci(t_print *tab, char *str, int len, long digit)
{
	if (len > tab->width && tab->preci == -1)
	{
		if (tab->sign)
			tab->length += write(1, "-", 1);
		if (digit >= 0)
		{
			if (!(tab->point && digit == 0 && !tab->p_star))
				tab->length += write(1, str, len);
		}
	}
}

void	sign_digit(t_print*tab, char *str, int len, long digit)
{
	if (tab->sign)
		ft_fill_space(tab->width - len - 1, tab);
	else
		ft_fill_space(tab->width - len, tab);
	if (digit > 0)
	{
		if (tab->sign && !tab->zero)
			tab->length += write(1, "-", 1);
		tab->length += write(1, str, len);
	}	
}

void	width_len_nopreci_dash(t_print *tab, char *str, int len)
{
	if (tab->sign)
	{
		tab->length += write(1, "-", 1);
		tab->width--;
	}
	tab->length += write(1, str, len);
	if (tab->width > tab->preci)
		tab->zero = 0;
	ft_fill_space(tab->width - len, tab);
}

void	width_len_nopreci(t_print *tab, char *str, int len, long digit)
{
	if (len <= tab->width && tab->preci == -1)
	{
		if (digit == 0)
		{
			if (tab->point)
			{
				if (tab->p_star)
					basic_width(tab, str, len);
				else
					ft_fill_space(tab->width, tab);
			}
			else
				basic_width(tab, str, len);
		}
		else if (tab->dash)
			width_len_nopreci_dash(tab, str, len);
		else
			sign_digit(tab, str, len, digit);
	}
}

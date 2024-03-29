/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:35:36 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:35:36 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_printf.h>

static int	ft_get_print_len(t_print *tab, int len)
{
	int	print_len;

	if (tab->dot)
	{
		if (tab->dot > len)
			print_len = tab->dot - 1;
		else
			print_len = len;
	}
	else if (tab->zero)
	{
		if (tab->wd > len)
			print_len = tab->wd;
		else
			print_len = len;
	}
	else
		print_len = len;
	return (print_len);
}

static void	ft_handle_left_align(t_print *tab, int print_len)
{
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(tab->d, " ", 1);
}

static void	ft_handle_zeros(t_print *tab, unsigned int n, int print_len)
{
	print_len -= ft_uintlen(n);
	while (print_len-- > 0)
		tab->tlen += write(tab->d, "0", 1);
}

static void	ft_handle_right_align(t_print *tab, int print_len)
{
	if (!tab->dash)
		return ;
	tab->wd -= print_len;
	while (tab->wd-- > 0)
		tab->tlen += write(tab->d, " ", 1);
}

void	ft_printf_uint(t_print *tab)
{
	unsigned int	n;
	unsigned int	pow_ten;
	char			c;
	int				print_len;

	n = va_arg(tab->args, unsigned int);
	pow_ten = 1;
	print_len = ft_get_print_len(tab, ft_uintlen(n));
	if (!tab->dash)
		ft_handle_left_align(tab, print_len);
	ft_handle_zeros(tab, n, print_len);
	while (n / pow_ten / 10)
		pow_ten *= 10;
	while (pow_ten)
	{
		c = n / pow_ten + '0';
		tab->tlen += write(tab->d, &c, 1);
		n %= pow_ten;
		pow_ten /= 10;
	}
	ft_handle_right_align(tab, print_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:27:29 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:27:29 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*check_number(unsigned long nb, int i)
{
	long	n;

	n = (long)nb;
	if ((n >= -2147483648 && nb <= 4294967295))
	{
		n = (unsigned int) n;
		return (ft_itoa_base(n, 16, i));
	}
	return (ft_uitoa_base(nb, 16, i));
}

void	ft_print_pointer(t_print *tab)
{
	long	digit;
	char	*str;
	char	*aux;
	int		len;

	digit = (long) va_arg(tab->args, void *);
	if (digit == 0 && tab->point && !tab->p_star)
		aux = ft_strdup("");
	else
		aux = check_number(digit, 0);
	str = ft_strjoin("0x", aux);
	len = ft_strlen(str);
	if (tab->width >= len)
		basic_width(tab, str, len);
	else
		tab->length += write(1, str, len);
	free(str);
	free(aux);
}

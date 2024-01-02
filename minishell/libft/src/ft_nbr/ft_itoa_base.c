/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:55:01 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:55:01 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

#include "libft/ft_nbr.h"
#include "libft/ft_str.h"
#include "libft/ft_mem.h"

char	*ft_itoa_base(int n, const char *base)
{
	int		i;
	char	*out;
	short	sign;
	short	is_neg;
	int		base_l;

	is_neg = 0;
	sign = 1;
	if (n < 0 && ++is_neg)
		sign = -1;
	base_l = (int)ft_strlen(base);
	out = ft_calloc(1, (size_t)(ft_intlen_base(n, base_l) + is_neg + 1));
	if (!out)
		return (NULL);
	i = 0;
	if (!n)
		out[i++] = '0';
	while (n)
	{
		out[i++] = base[n % (int)base_l * sign];
		n /= (int)base_l;
	}
	if (sign == -1)
		out[i++] = '-';
	return (ft_strrev(out));
}

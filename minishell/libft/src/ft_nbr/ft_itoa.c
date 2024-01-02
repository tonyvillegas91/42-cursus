/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:55:05 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:55:05 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

static char	*int_to_str(int n, int pow_ten, short sign, char *out)
{
	int	i;

	i = 0;
	if (sign == -1)
		i++;
	while (pow_ten)
	{
		out[i++] = (char)(n / pow_ten * sign + '0');
		n %= pow_ten;
		pow_ten /= 10;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_itoa(int n)
{
	size_t			i;
	char			*out;
	short			sign;
	int				pow_ten;

	i = 1;
	pow_ten = 1;
	sign = 0;
	if (n < 0)
		sign++;
	while (n / pow_ten / 10 && i++)
		pow_ten *= 10;
	out = (char *)malloc(i + (size_t)sign + 1);
	if (!out)
		return (NULL);
	if (sign == 1)
	{
		out[0] = '-';
		sign = -1;
	}
	else
		sign++;
	return (int_to_str(n, pow_ten, sign, out));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:29:00 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:29:00 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Allocates (with malloc(3)) and returns a string
** representing the integer received as an argument.
** Negative numbers must be handled.
*/

#include "libft.h"

static int	ft_length(int n)
{
	int		len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_write(int len, int n, char *str)
{
	unsigned int	nb;
	int				sign;

	nb = 0;
	sign = 0;
	if (n < 0)
	{
		sign = -1;
		nb = -n;
	}
	else
		nb = n;
	while (len >= 0)
	{
		str[len] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_length(n);
	if (n <= 0)
	{
		str = malloc(sizeof(char *) * (len + 2));
		if (!str)
			return (NULL);
		str = ft_write(len, n, str);
		str[len + 1] = '\0';
	}
	else
	{
		str = malloc(sizeof(char *) * (len + 1));
		if (!str)
			return (NULL);
		str = ft_write(len - 1, n, str);
		str[len] = '\0';
	}
	return (str);
}

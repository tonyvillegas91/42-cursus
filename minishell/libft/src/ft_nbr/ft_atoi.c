/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:14 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:52:14 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_char.h"

int	ft_atoi(const char *str)
{
	short			sign;
	unsigned char	digit;
	unsigned long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\f' || *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' && str++)
		sign = -1;
	else if (*str == '+')
		str++;
	while (1)
	{
		digit = (unsigned char)(*str++) - '0';
		if (digit > 9)
			break ;
		result = result * 10 + digit;
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
	}
	return ((int)result * sign);
}

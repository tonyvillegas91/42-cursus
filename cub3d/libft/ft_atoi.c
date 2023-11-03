/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:19:54 by antville          #+#    #+#             */
/*   Updated: 2021/04/28 11:45:57 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\f' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					negative;

	negative = 1;
	res = 0;
	while (my_isspace(*str))
		str++;
	if (*str == '-')
	{
		negative = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + (*str++ - 48);
	if (res > 9223372036854775807 && negative > 0)
		return (-1);
	if (res - 1 > 9223372036854775807 && negative < 0)
		return (0);
	return (negative * res);
}
/*int main(void)
{
	char *str = "-4y58knjh";
	printf("%d\n", atoi(str));
	printf("%d\n", ft_atoi(str));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:01:15 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:01:15 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <libft/ft_fd.h>

int	ft_putnbr_fd(int n, int fd)
{
	int					cnt;
	short				sign;
	unsigned int		pow_ten;

	cnt = 0;
	pow_ten = 1;
	sign = 0;
	if (n < 0 && ++sign)
		n = -n;
	while (n / pow_ten / 10)
		pow_ten *= 10;
	if (sign)
		cnt += ft_putchar_fd('-', fd);
	while (pow_ten)
	{
		cnt += ft_putchar_fd(n / pow_ten + '0', fd);
		n %= pow_ten;
		pow_ten /= 10;
	}
	return (cnt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 15:04:10 by antville          #+#    #+#             */
/*   Updated: 2021/04/12 18:38:59 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	tmp_nbr;

	if (fd < 0)
		return ;
	if (n < 0)
		tmp_nbr = -1 * n;
	else
		tmp_nbr = n;
	if (n < 0)
		write(fd, "-", 1);
	if (tmp_nbr > 9)
	{
		ft_putnbr_fd((tmp_nbr / 10), fd);
		ft_putnbr_fd((tmp_nbr % 10), fd);
	}
	else
	{
		c = tmp_nbr + '0';
		write(fd, &c, 1);
	}
}

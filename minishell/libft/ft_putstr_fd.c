/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:03:15 by antville          #+#    #+#             */
/*   Updated: 2021/04/16 13:42:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s != 0)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
/*int main(void)
{
	
	char	str[] = "PUTSTR_FD";
	printf("\033[1;33m%s\033[0m\n", str);
	ft_putstr_fd("Bonjour", 2);
	ft_putstr_fd(" les", 1);
	ft_putstr_fd(" amis", 2);
	ft_putstr_fd(" !", 1);
	ft_putstr_fd("\n", 3);
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd("\n", 1);
	printf("\033[1;32m%s passed.\033[0m\n\n", str);
}*/

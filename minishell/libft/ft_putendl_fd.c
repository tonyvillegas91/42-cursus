/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:08:31 by antville          #+#    #+#             */
/*   Updated: 2021/04/16 13:08:58 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	char	endline;

	if (s)
	{
		endline = '\n';
		while (*s != 0)
		{
			write(fd, s, 1);
			s++;
		}
		write(fd, &endline, 1);
	}
}

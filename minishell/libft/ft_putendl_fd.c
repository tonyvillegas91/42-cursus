/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:30:48 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:30:48 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* Outputs the string ’s’ to the given file
descriptor, followed by a newline. */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

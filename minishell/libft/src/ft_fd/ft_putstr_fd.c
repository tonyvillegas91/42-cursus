/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:50:33 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:50:33 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

#include "libft/ft_str.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (0);
	return ((int)write(fd, s, ft_strlen(s)));
}

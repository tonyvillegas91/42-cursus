/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:42:38 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:42:38 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_fd.h>

int	ft_putendl_fd(char *s, int fd)
{
	int	cnt;

	if (!s)
		return (0);
	cnt = 0;
	cnt += ft_putstr_fd(s, fd);
	cnt += ft_putchar_fd('\n', fd);
	return (cnt);
}

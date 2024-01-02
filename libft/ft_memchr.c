/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:06:43 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 20:06:43 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*s1;
	size_t		i;

	s1 = s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)s1[i] == (unsigned char)c)
			return ((unsigned char *) s1 + i);
		i++;
	}
	return (0);
}

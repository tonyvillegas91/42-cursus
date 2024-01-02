/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:06:59 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 20:06:59 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	s = src;
	d = dst;
	i = 0;
	if (d == 0 && s == 0)
		return (0);
	if (s > d)
		ft_memcpy(d, s, len);
	else
		while (len--)
			*((unsigned char *) dst + len) = *((unsigned char *) src + len);
	return (dst);
}

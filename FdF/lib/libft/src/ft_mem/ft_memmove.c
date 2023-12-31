/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:04:39 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:04:39 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <libft/ft_mem.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*save;

	if (!dst && !src)
		return (NULL);
	save = dst;
	if (src < dst)
	{
		dst += len;
		src += len;
		while (len--)
			*(unsigned char *)--dst = *(unsigned char *)--src;
	}
	else
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (save);
}

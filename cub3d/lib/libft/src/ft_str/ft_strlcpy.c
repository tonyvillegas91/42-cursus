/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:48:56 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:48:56 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_str.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*save;

	if (!dstsize)
		return (ft_strlen(src));
	save = (char *)src;
	dstsize--;
	while (*src && dstsize--)
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(save));
}

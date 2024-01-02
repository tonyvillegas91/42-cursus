/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:59:42 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:59:42 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_str.h"

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

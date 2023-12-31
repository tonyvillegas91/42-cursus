/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 10:53:06 by antville          #+#    #+#             */
/*   Updated: 2021/04/05 12:09:38 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	itr;
	size_t	destlen;
	size_t	srclen;

	itr = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	if (size <= destlen)
		return (size + srclen);
	while (src[itr] != '\0' && itr < size - destlen - 1)
	{
		dest[destlen + itr] = src[itr];
		itr++;
	}
	dest[destlen + itr] = '\0';
	return (destlen + srclen);
}

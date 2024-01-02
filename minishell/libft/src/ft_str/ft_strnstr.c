/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:01:24 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 13:01:24 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_str.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (haystack[i] && haystack[i] == needle[i] && len - i)
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			++i;
		}
		len--;
		haystack++;
	}
	return (NULL);
}

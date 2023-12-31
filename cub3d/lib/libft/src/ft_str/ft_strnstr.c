/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:49:16 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:49:16 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_str.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = -1;
		while (haystack[++i] && haystack[i] == needle[i] && len - i)
			if (!needle[i + 1])
				return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}

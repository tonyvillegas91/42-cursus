/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:49:20 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:49:20 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_str.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)&s[len]);
	s += len;
	while (len--)
	{
		if (*--s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:31:06 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:31:06 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		x;
	int		len;

	x = 0;
	len = ft_strlen(s);
	while (x < len + 1)
	{
		if (s[x] == (char)c)
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}

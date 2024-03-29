/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:25:39 by antville          #+#    #+#             */
/*   Updated: 2021/05/03 15:46:28 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*s1;
	size_t		i;
	size_t		x;

	s1 = s;
	x = ft_strlen(s1);
	if ((char)c == 0)
		return ((char *) s1 + x);
	i = 0;
	while (i < x + 1)
	{
		if (s1[i] == (char)c)
			return ((char *) s1 + i);
		i++;
	}
	return (0);
}

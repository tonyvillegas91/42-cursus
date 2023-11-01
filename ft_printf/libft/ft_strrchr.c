/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:38:47 by antville          #+#    #+#             */
/*   Updated: 2021/04/19 16:09:12 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	t;
	size_t	i;

	t = ft_strlen(s);
	i = 0;
	while (i < t + 1)
	{
		if (s[t] == (char)c)
			return ((char *) s + t);
		t--;
	}
	return (0);
}

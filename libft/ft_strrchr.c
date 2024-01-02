/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:08:19 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 20:08:19 by antville         ###   ########.fr       */
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

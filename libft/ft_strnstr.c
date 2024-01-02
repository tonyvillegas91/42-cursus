/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:08:14 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 20:08:14 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strnstr(const char *hay, const char *ne, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (ne[i] == '\0')
		return ((char *) hay);
	while (hay[i] != '\0')
	{
		j = 0;
		while (hay[i + j] == ne[j] && (i + j) < len)
		{
			if (ne[j + 1] == '\0')
				return ((char *) hay + i);
			j++;
		}
		i++;
	}
	return (0);
}

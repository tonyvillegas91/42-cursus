/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:37:58 by antville          #+#    #+#             */
/*   Updated: 2021/04/02 12:40:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	int		i;
	int		len;

	len = ft_strlen(s);
	duplicate = malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}

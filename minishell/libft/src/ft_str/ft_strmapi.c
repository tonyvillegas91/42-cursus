/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:01:14 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 13:01:14 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_str.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out[i] = f(i, (char)s[i]);
		++i;
	}
	out[i] = '\0';
	return (out);
}

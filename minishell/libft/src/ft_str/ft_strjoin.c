/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:59:34 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:59:34 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_str.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*out;

	if (!s1 || !s2)
		return (NULL);
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (NULL);
	ft_strcpy(out, s1);
	ft_strcat(out, s2);
	return (out);
}

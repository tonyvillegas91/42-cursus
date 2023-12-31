/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:48:33 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:48:33 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_str.h>

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	len;

	len = ft_strlen(s1);
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	return (ft_strcpy(cpy, s1));
}

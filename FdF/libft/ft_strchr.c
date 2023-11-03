/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:43:43 by antville          #+#    #+#             */
/*   Updated: 2021/04/14 12:45:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != 0)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
	return (0);
}
/*int main(void)
{
   char *src = "Esta es *la cadena de prueba";
   printf("%s\n", strchr(src, '*'));
   printf("%s\n", ft_strchr( src, '*'));
}*/

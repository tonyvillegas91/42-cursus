/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:51:47 by antville          #+#    #+#             */
/*   Updated: 2021/04/15 11:13:21 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		pos;

	pos = ft_strlen(s);
	while (pos >= 0)
	{
		if (s[pos] == (char)c)
			return ((char *)&s[pos]);
		pos--;
	}
	return (0);
}
/*int main(void)
{
   char *src = "Esta es *la cadena *de prueba";
   printf("%s\n", strrchr(src, '*'));
   printf("%s\n", ft_strrchr( src, '*'));
}*/

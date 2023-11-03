/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:03:05 by antville          #+#    #+#             */
/*   Updated: 2021/04/22 16:56:09 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*n == 0)
		return ((char *)h);
	while (h[i] != 0 && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && n[j] != 0 && j + i < len)
			j++;
		if (j == ft_strlen(n))
			return ((char *)&h[i]);
		i++;
	}
	return (0);
}
/*int main(void)
{
   char *str = "Esta es *la cadena de prueba";
   char *substr = " es";
   printf("%s\n", strnstr(str, substr, 7));
   printf("%s\n", ft_strnstr(str, substr, 7));
}*/

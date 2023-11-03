/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:16:08 by antville          #+#    #+#             */
/*   Updated: 2021/04/26 15:22:09 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dst;
	if (a == 0 && b == 0)
		return (0);
	while (n--)
	{
		*b++ = *a++;
	}
	return (dst);
}
/*int main ()
{
   const char src[50] = "http://www.w3cschool.cc";
   char dest[50];

   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}*/

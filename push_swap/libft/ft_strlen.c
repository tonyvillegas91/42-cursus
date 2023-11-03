/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:10:38 by antville          #+#    #+#             */
/*   Updated: 2021/04/14 11:15:11 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != 0)
	{
		len++;
	}
	return (len);
}
/*int main ()
{
   char str[50];
   int len;

   strcpy(str, "This is w3cschool.cc");

   len = strlen(str);
   printf("|%s| 的长度是 |%d|\n", str, len);

   return(0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:59:22 by antville          #+#    #+#             */
/*   Updated: 2021/04/26 15:15:27 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len > 0)
	{
		*a++ = (char)c;
		len--;
	}
	return (b);
}
/*int		main(void)
{
	char	buffer[] = "This is a test of the memset function";
	char	buffer1[] = "This is a test of the memset function";

	memset(buffer, '9', 0);
	ft_memset(buffer1, '9', 0);
	printf("c: %s\n", buffer);
	printf("ft: %s\n", buffer1);
}*/

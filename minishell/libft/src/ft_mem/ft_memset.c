/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:51:56 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:51:56 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_mem.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len--)
		*(p++) = (unsigned char)c;
	return (b);
}
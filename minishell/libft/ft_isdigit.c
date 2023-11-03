/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:33:01 by antville          #+#    #+#             */
/*   Updated: 2021/04/14 15:35:25 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
/*int main(void)
{
	char *str = "-4y58knjh";
	printf("%d\n", isdigit(str[0]));
	printf("%d\n", ft_isdigit(str[0]));
}*/

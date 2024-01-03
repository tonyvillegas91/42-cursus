/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_str_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:28:00 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:28:00 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*del_str_pos(char *str, int n)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	j = 0;
	aux = malloc(ft_strlen(str));
	while (str[i])
	{
		if (i == n)
			i++;
		aux[j] = str[i];
		i++;
		j++;
	}
	aux[j] = '\0';
	return (aux);
}

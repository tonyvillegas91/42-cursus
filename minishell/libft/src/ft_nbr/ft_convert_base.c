/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:21 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:52:21 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stddef.h>

#include "libft/ft_nbr.h"

char	*ft_convert_base(char *n, char *base_from, char *base_to)
{
	int	tmp;

	if (!n || !base_from || !base_to)
		return (NULL);
	tmp = ft_atoi_base(n, base_from);
	return (ft_itoa_base(tmp, base_to));
}

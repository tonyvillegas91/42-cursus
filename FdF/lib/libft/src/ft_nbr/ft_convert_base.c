/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:05:03 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:05:03 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <libft/ft_nbr.h>
#include <stddef.h>

char	*ft_convert_base(char *n, char *base_from, char *base_to)
{
	int	tmp;

	if (!n || !base_from || !base_to)
		return (NULL);
	tmp = ft_atoi_base(n, base_from);
	return (ft_itoa_base(tmp, base_to));
}

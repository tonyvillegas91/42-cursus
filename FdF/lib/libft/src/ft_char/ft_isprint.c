/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:29:58 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:29:58 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}

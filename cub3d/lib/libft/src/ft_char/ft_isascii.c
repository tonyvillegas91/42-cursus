/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:40:15 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:40:15 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

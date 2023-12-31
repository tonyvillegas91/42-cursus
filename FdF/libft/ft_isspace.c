/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:32:51 by antville          #+#    #+#             */
/*   Updated: 2021/07/01 16:58:52 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(const char c)
{
	return (c == ' ' || (c <= 13 && c >= 9));
}
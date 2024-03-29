/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:44:43 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:44:43 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_intlen(int n)
{
	int	cnt;

	cnt = !n;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:45:10 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:45:10 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_ulonglen(unsigned long n)
{
	int	cnt;

	cnt = 1;
	while (n > 9)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

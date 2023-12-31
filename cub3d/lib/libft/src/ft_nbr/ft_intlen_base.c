/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:44:39 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:44:39 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_intlen_base(int n, int base_len)
{
	int	cnt;

	cnt = !n;
	while (n)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}

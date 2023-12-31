/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:05:48 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:05:48 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	ft_ulonglen_base(unsigned long n, int base_len)
{
	int	cnt;

	cnt = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}

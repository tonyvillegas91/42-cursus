/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulonglen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:55:20 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:55:20 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_ulonglen_base(unsigned long n, int base_len)
{
	int	cnt;

	cnt = 1;
	while (n >= (unsigned long)base_len)
	{
		n /= (unsigned long)base_len;
		cnt++;
	}
	return (cnt);
}

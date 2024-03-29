/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:34:25 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:34:25 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_uintlen_base(unsigned int n, int base_len)
{
	int	cnt;

	cnt = 1;
	while (n >= (unsigned int)base_len)
	{
		n /= (unsigned int)base_len;
		cnt++;
	}
	return (cnt);
}

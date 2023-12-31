/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:06:53 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:06:53 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <libft/ft_printf.h>

int	handle_dprintf(int d, const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = handle_dprintf(STDOUT_FILENO, format, args);
	va_end(args);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:56:58 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:56:58 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/ft_printf.h"

int	handle_dprintf(int d, const char *format, va_list args);

int	ft_dprintf(int d, const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = handle_dprintf(d, format, args);
	va_end(args);
	return (ret);
}

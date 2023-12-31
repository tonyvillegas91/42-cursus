/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:50:02 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:50:02 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

/* print perror and exit */
void	perror_exit(const char *s)
{
	if (s != NULL)
		perror(s);
	else if (NAME != NULL)
		perror(NAME);
	else
		perror("error");
	exit(EXIT_FAILURE);
}

/* return perror with custom error code */
int	perror_ret(const char *s, int ret_code)
{
	if (s != NULL)
		perror(s);
	else if (NAME != NULL)
		perror(NAME);
	else
		perror("error");
	return (ret_code);
}

/* return custom error with custom error code */
int	error_ret(const char *s, int ret_code)
{
	if (NAME != NULL)
	{
		write(STDERR_FILENO, NAME, ft_strlen(NAME));
	}
	else
		write(STDERR_FILENO, "error", 5);
	write(STDERR_FILENO, ": ", 2);
	if (s)
		write(STDERR_FILENO, s, ft_strlen(s));
	exit(ret_code);
	return (ret_code);
}

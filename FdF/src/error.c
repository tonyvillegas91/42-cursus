/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:38:30 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:38:30 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_printf.h>
#include <stdio.h>

// Función para imprimir un mensaje de error y salir del programa.
void err_exit(const char *err, const char *msg)
{
    ft_dprintf(STDERR_FILENO, "%s: %s\n", err, msg);
    exit(EXIT_FAILURE);
}

// Función para imprimir un mensaje de error perror y salir del programa.
void perror_exit(const char *str)
{
    perror(str);
    exit(EXIT_FAILURE);
}


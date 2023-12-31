/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:38:20 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:38:20 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fdf.h>
#include <mlx.h>
#include <libft/ft_mem.h>
#include <libft/ft_printf.h>
#include <stdlib.h>

// Función principal que inicia la aplicación utilizando la librería minilibx.
int mlx_main(t_map *map)
{
    t_vars *vars;

    // Imprime un mensaje informativo.
    ft_printf("Starting minilibx...\n");

    // Asigna memoria para la estructura de variables (t_vars).
    vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
    if (!vars)
        err_exit("Error", MAL_ERROR);

    // Inicializa las variables y la estructura de minilibx.
    if (initialise_vars(vars, map))
    {
        // Si hay un error al inicializar, libera la memoria y muestra un mensaje de error.
        free_all(vars);
        err_exit("Error", MAL_ERROR);
    }

    // Inicializa la conexión con minilibx.
    initialise_mlx(vars);

    // Configura los hooks para manejar eventos de teclado y cierre de ventana.
    mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
    mlx_hook(vars->win, 17, 1L << 17, close_win, vars);

    // Dibuja la escena inicial.
    draw(vars);

    // Inicia el bucle principal de minilibx.
    mlx_loop(vars->mlx);

    // Libera la memoria y sale con un código de éxito al cerrar el programa.
    free_all(vars);
    return (EXIT_SUCCESS);
}

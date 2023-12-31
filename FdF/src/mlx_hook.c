/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:38:50 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:38:50 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

// Función para cerrar la ventana y liberar la memoria al presionar la tecla Esc.
int close_win(t_vars *vars)
{
    // Llama a la función para liberar toda la memoria asignada.
    free_all(vars);

    // Sale del programa con un código de éxito.
    exit(EXIT_SUCCESS);

    // Retorna 0 para indicar que la función se ejecutó sin problemas.
    return (0);
}

// Función para manejar eventos de teclado.
int key_hook(int keycode, t_vars *vars)
{
    // Verifica la tecla presionada y realiza acciones correspondientes.
    if (keycode == KEY_ESC)
        close_win(vars);
    if (keycode == KEY_R)
        reset_vars(vars);
    if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A || keycode == KEY_D)
        handle_move(keycode, vars);
    if (keycode == KEY_UP || keycode == KEY_DOWN)
        handle_zoom(keycode, vars);
    if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_I || keycode == KEY_K || keycode == KEY_O || keycode == KEY_L)
        handle_rot(keycode, vars);
    if (keycode == KEY_MINUS || keycode == KEY_PLUS)
        handle_flattening(keycode, vars);
    if (keycode == KEY_P)
    {
        // Alterna entre perspectivas isométrica y paralela al presionar la tecla P.
        if (vars->iso)
            vars->iso = 0;
        else
            vars->iso = 1;
    }

    // Llama a la función para dibujar la escena.
    draw(vars);

    // Retorna 0 para indicar que la función se ejecutó sin problemas.
    return (0);
}

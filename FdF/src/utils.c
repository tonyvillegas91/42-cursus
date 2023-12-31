/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:39:06 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:39:06 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>
#include <stdlib.h>

// Función para liberar la memoria asignada a un arreglo de cadenas (split).
void free_split(char **split)
{
    int i;

    i = -1;
    while (split[++i])
        free(split[i]);
    free(split);
}

// Función para liberar la memoria asignada a la estructura t_vars y su contenido.
void free_vars(t_vars *vars)
{
    // Libera la memoria del mapa y la imagen asociada.
    free_map(vars->map);
    if (vars->img)
        free(vars->img);

    // Libera la memoria de la estructura t_vars.
    free(vars);
}

// Función para liberar la memoria y cerrar la ventana antes de salir del programa.
void free_all(t_vars *vars)
{
    // Destruye la ventana y la imagen asociada.
    mlx_destroy_window(vars->mlx, vars->win);
    mlx_destroy_image(vars->mlx, vars->img->img);

    // Llama a la función para liberar la memoria de la estructura t_vars y su contenido.
    free_vars(vars);
}

// Función para crear un nuevo punto (t_point) con coordenadas y color.
t_point new_point(int x, int y, t_vars *vars)
{
    t_point out;

    out.x = x;
    out.y = y;
    out.z = vars->map->z_mt[y][x];

    // Verifica si el mapa tiene información de color.
    if (vars->map->iscolor)
        out.color = vars->map->clrs[y][x];
    else
        out.color = get_z_color(vars, out.z);

    return (out);
}

// Función para obtener las coordenadas ajustadas según las transformaciones.
t_point get_coords(t_vars *vars, t_point point)
{
    // Aplica transformaciones de escala, rotación e isométricas a las coordenadas del punto.
    point.x *= vars->zoom;
    point.y *= vars->zoom;
    point.z *= (vars->zoom / 10) * vars->flat;
    rot_x(vars, &point.y, &point.z);
    rot_y(vars, &point.x, &point.z);
    rot_z(vars, &point.x, &point.y);
    isometric(vars, &point.x, &point.y, point.z);

    // Aplica traslación a las coordenadas del punto.
    point.x += vars->shift_x;
    point.y += vars->shift_y;

    return (point);
}


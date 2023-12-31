/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:37:17 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:37:17 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fdf.h>
#include <mlx.h>

// Función que calcula el porcentaje entre dos valores.
static double percent(int start, int end, int current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    if (!distance)
        return (1.0);
    return (placement / distance);
}

// Función que obtiene un valor de luz entre dos extremos dado un porcentaje.
static int get_light(int start, int end, double percent)
{
    return ((int)((1 - percent) * start + percent * end));
}

// Función que obtiene el color entre dos puntos dados un punto actual y un delta.
int get_color(t_point current, t_point start, t_point end, t_point delta)
{
    int r;
    int g;
    int b;
    double percentage;

    // Si los colores de los puntos actual y final son iguales, devuelve el color actual.
    if (current.color == end.color)
        return (current.color);

    // Calcula el porcentaje basado en la coordenada que tenga un delta mayor.
    if (delta.x > delta.y)
        percentage = percent(start.x, end.x, current.x);
    else
        percentage = percent(start.y, end.y, current.y);

    // Obtiene los componentes de color interpolados.
    r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
    g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
    b = get_light(start.color & 0xFF, end.color & 0xFF, percentage);

    // Combina los componentes de color y devuelve el color resultante.
    return ((r << 16) | (g << 8) | b);
}

// Función que obtiene un color basado en la altura z y porcentajes predefinidos.
int get_z_color(t_vars *vars, int cur_z)
{
    double percentage;

    // Calcula el porcentaje de la altura actual en relación con la altura mínima y máxima.
    percentage = percent(vars->map->min_z, vars->map->max_z, cur_z);

    // Asigna colores predefinidos en base al rango de porcentajes.
    if (percentage < 0.2)
        return (COLOR_1);
    else if (percentage < 0.4)
        return (COLOR_2);
    else if (percentage < 0.6)
        return (COLOR_3);
    else if (percentage < 0.8)
        return (COLOR_4);
    else
        return (COLOR_5);
}


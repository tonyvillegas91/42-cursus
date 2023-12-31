/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:37:48 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:37:48 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fdf.h>
#include <libft/ft_mem.h>
#include <mlx.h>
#include <math.h>

// Función para dibujar el menú de controles en la ventana.
static void draw_menu(t_vars *vars)
{
    int y;
    void *mlx;
    void *win;

    mlx = vars->mlx;
    win = vars->win;
    y = 0;
    mlx_string_put(mlx, win, 15, y += 15, WHITE, "Controls:");
    // ... (más texto del menú)
}

// Función para calcular el valor absoluto de un entero.
static int ft_abs(int a)
{
    if (a < 0)
        return (-(a));
    return (a);
}

// Función para inicializar las variables utilizadas en el algoritmo de Bresenham.
static void initialise_bresenham(t_point *start, t_point *end,
    t_point *delta, t_point *sign)
{
    delta->x = ft_abs(end->x - start->x);
    delta->y = ft_abs(end->y - start->y);
    sign->x = -1;
    sign->y = -1;
    if (start->x < end->x)
        sign->x = 1;
    if (start->y < end->y)
        sign->y = 1;
}

// Función que implementa el algoritmo de Bresenham para dibujar líneas.
static void bresenham(t_vars *vars, t_point start, t_point end)
{
    t_point cur;
    t_point sign;
    t_point delta;
    int line;
    int tmp;

    initialise_bresenham(&start, &end, &delta, &sign);
    line = delta.x - delta.y;
    cur = start;
    while (cur.x != end.x || cur.y != end.y)
    {
        img_pixel_put(vars, cur.x, cur.y, get_color(cur, start, end, delta));
        tmp = line * 2;
        if (tmp > -delta.y)
        {
            line -= delta.y;
            cur.x += sign.x;
        }
        if (tmp < delta.x)
        {
            line += delta.x;
            cur.y += sign.y;
        }
    }
}

// Función principal para dibujar la escena.
void draw(t_vars *vars)
{
    int x;
    int y;

    // Limpia el contenido de la imagen.
    ft_bzero(vars->img->addr, WIN_H * WIN_W * (vars->img->bpp / 8));

    // Verifica si se ha aplicado el zoom.
    if (vars->zoom)
    {
        y = -1;
        while (++y < vars->map->h)
        {
            x = -1;
            while (++x < vars->map->w)
            {
                if (x < vars->map->w - 1)
                    bresenham(vars,
                        get_coords(vars, new_point(x, y, vars)),
                        get_coords(vars, new_point(x + 1, y, vars)));
                if (y < vars->map->h - 1)
                    bresenham(vars,
                        get_coords(vars, new_point(x, y, vars)),
                        get_coords(vars, new_point(x, y + 1, vars)));
            }
        }
    }

    // Coloca la imagen en la ventana.
    mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);

    // Dibuja el menú de controles.
    draw_menu(vars);
}


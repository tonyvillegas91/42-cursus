/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 11:38:25 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 11:38:25 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <fdf.h>
#include <mlx.h>
#include <libft/ft_mem.h>

// Función auxiliar para calcular el máximo entre dos números.
static int ft_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

// Función para restablecer las variables de la estructura t_vars a sus valores iniciales.
void reset_vars(t_vars *vars)
{
    // Calcula el zoom inicial basado en el tamaño de la ventana y las dimensiones del mapa.
    vars->zoom = ft_max((WIN_W / vars->map->w / 2), (WIN_H / vars->map->h / 2));
    
    // Centra el mapa en la ventana.
    vars->shift_x = WIN_W / 2;
    vars->shift_y = (WIN_H - vars->map->h * vars->zoom) / 2;

    // Configura otras variables a sus valores iniciales.
    vars->iso = 1;
    vars->flat = 1;
    vars->rot_x = 0;
    vars->rot_y = 0;
    vars->rot_z = 0;
}

// Función para inicializar las variables de la estructura t_vars.
int initialise_vars(t_vars *vars, t_map *map)
{
    // Asigna el mapa a la estructura t_vars.
    vars->map = map;

    // Asigna memoria para la estructura de la imagen (t_img).
    vars->img = (t_img *)ft_calloc(1, sizeof(t_img));
    if (!vars->img)
        return (1);

    // Restablece las variables a sus valores iniciales.
    reset_vars(vars);

    // Retorna 0 para indicar que la inicialización fue exitosa.
    return (0);
}

// Función para inicializar la conexión con minilibx y crear la ventana.
void initialise_mlx(t_vars *vars)
{
    // Inicializa minilibx.
    vars->mlx = mlx_init();

    // Crea una nueva imagen en blanco.
    vars->img->img = mlx_new_image(vars->mlx, WIN_W, WIN_H);

    // Obtiene información sobre la imagen.
    vars->img->addr = mlx_get_data_addr(vars->img->img,
                                        &vars->img->bpp, &vars->img->sz_l, &vars->img->endian);

    // Crea una nueva ventana con el título "fdf".
    vars->win = mlx_new_window(vars->mlx, WIN_W, WIN_H, "fdf");
}


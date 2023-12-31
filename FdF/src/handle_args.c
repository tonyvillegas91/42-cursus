/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:38:35 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:38:35 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_fd.h>
#include <libft/ft_char.h>
#include <libft/ft_str.h>
#include <libft/ft_nbr.h>
#include <libft/ft_printf.h>
#include <fcntl.h>

// Función auxiliar para convertir un carácter a minúsculas.
static void char_tolower(char *c)
{
    *c = ft_tolower(*c);
}

// Función para parsear el color de una cadena y devolver su valor entero.
static int parse_color(t_map *map, char *s)
{
    while (*s && (ft_isdigit(*s) || *s == '-' || *s == '+' || *s == ','))
        s++;
    if (*s && *s == 'x')
    {
        map->iscolor = 1;
        ft_striter(s + 1, char_tolower);
        return (ft_atoi_base(s + 1, LHEX));
    }
    else
        return (WHITE);
    return (0);
}

// Función para llenar la matriz con datos del archivo.
static void fill_matrix(t_map *map, int fd)
{
    int x;
    int y;
    char *line;
    char **split;

    y = -1;
    while (++y < map->h)
    {
        line = ft_get_next_line(fd);
        split = ft_split(line, ' ');
        if (!split)
        {
            free_map(map);
            err_exit("Error", MAL_ERROR);
        }
        x = -1;
        while (++x < map->w)
        {
            map->z_mt[y][x] = ft_atoi(split[x]);
            map->clrs[y][x] = parse_color(map, split[x]);
        }
        free_split(split);
        free(line);
    }
}

// Función para parsear el archivo y llenar la estructura del mapa.
static void parse_file(t_map *map, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        free_map(map);
        perror_exit(file);
    }
    fill_matrix(map, fd);
    close(fd);
}

// Función principal para manejar los argumentos y leer el archivo.
void handle_args(t_map **map, int ac, char **av)
{
    char *file;

    // Verifica si hay un número correcto de argumentos.
    if (ac != 2)
        err_exit("Error", "Invalid arguments");

    // Imprime un mensaje informativo.
    ft_printf("Reading map...\n");

    // Obtiene el nombre del archivo a partir de los argumentos.
    file = av[1];

    // Inicializa la estructura del mapa y asigna memoria.
    *map = initialise_map(file);
    alloc_map(*map);

    // Parsea el archivo y llena la estructura del mapa.
    parse_file(*map, file);

    // Obtiene los valores mínimos y máximos de la altura z.
    get_min_max_z(*map);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:38:46 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:38:46 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft/ft_mem.h>
#include <libft/ft_str.h>
#include <libft/ft_fd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// Función para obtener los valores mínimo y máximo de la altura z en el mapa.
void get_min_max_z(t_map *map)
{
    int x;
    int y;

    y = -1;
    while (++y < map->h)
    {
        x = -1;
        while (++x < map->w)
        {
            if (map->z_mt[y][x] < map->min_z)
                map->min_z = map->z_mt[y][x];
            else if (map->z_mt[y][x] > map->max_z)
                map->max_z = map->z_mt[y][x];
        }
    }
}

// Función para liberar la memoria asignada para la estructura del mapa.
void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
    if (map->z_mt)
    {
        i = -1;
        while (++i < map->h)
        {
            if (map->z_mt[i])
                free(map->z_mt[i]);
        }
        free(map->z_mt);
    }
    if (map->clrs)
    {
        i = -1;
        while (++i < map->h)
        {
            if (map->clrs[i])
                free(map->clrs[i]);
        }
        free(map->clrs);
    }
    free(map);
}

// Función para asignar memoria para la estructura del mapa.
void alloc_map(t_map *map)
{
    int i;

    map->z_mt = (int **)malloc(sizeof(int *) * map->h);
    map->clrs = (int **)malloc(sizeof(int *) * map->h);
    if (!map->z_mt || !map->clrs)
    {
        free_map(map);
        err_exit("Error", MAL_ERROR);
    }
    i = -1;
    while (++i < map->h)
    {
        map->z_mt[i] = (int *)malloc(sizeof(int) * map->w);
        map->clrs[i] = (int *)malloc(sizeof(int) * map->w);
        if (!map->z_mt[i] || !map->clrs[i])
        {
            free_map(map);
            err_exit("Error", MAL_ERROR);
        }
    }
}

// Función auxiliar para contar el número de números en una línea del mapa.
static int cnt_nbrs(t_map *map, char *line, char *file)
{
    int cnt;
    char **split;

    if (!line)
    {
        free_map(map);
        err_exit(file, "is an empty map");
    }
    split = ft_split(line, ' ');
    if (!split)
    {
        free_map(map);
        err_exit("Error", MAL_ERROR);
    }
    cnt = 0;
    while (split[cnt])
        cnt++;
    free_split(split);
    return (cnt);
}

// Función para inicializar la estructura del mapa.
t_map *initialise_map(char *file)
{
    int fd;
    t_map *map;
    char *line;

    // Asigna memoria para la estructura del mapa.
    map = (t_map *)ft_calloc(1, sizeof(t_map));
    if (!map)
        return (NULL);

    // Abre el archivo para leer el número de columnas (width) en la primera línea.
    fd = open(file, O_RDONLY);
    if (fd < 0)
        perror_exit(file);
    line = ft_get_next_line(fd);
    map->w = cnt_nbrs(map, line, file);
    while (line)
    {
        map->h++;
        free(line);
        line = ft_get_next_line(fd);
    }
    free(line);
    close(fd);

    // Retorna la estructura inicializada.
    return (map);
}


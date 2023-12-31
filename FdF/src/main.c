/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:38:41 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 14:38:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

// Función principal que maneja la ejecución del programa.
int main(int ac, char **av)
{
    t_map *map;

    // Inicializa un puntero a la estructura del mapa.
    map = NULL;

    // Maneja los argumentos de línea de comandos y llena la estructura del mapa.
    handle_args(&map, ac, av);

    // Llama a la función principal de la interfaz gráfica (mlx).
    mlx_main(map);

    // Retorna 0 para indicar una ejecución exitosa.
    return (0);
}


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

int	main(int ac, char **av)
{
	t_map	*map;

	map = NULL;
	handle_args(&map, ac, av);
	mlx_main(map);
	return (0);
}

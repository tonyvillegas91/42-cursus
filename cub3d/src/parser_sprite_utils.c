/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:51:21 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:51:21 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	store_sprites(const t_map *map, char **aux, int *i, int *id)
{
	map->spaux[(*id)].id = (*id);
	map->spaux[(*id)].type = ft_strdup(aux[0]);
	(*id)++;
	(*i)++;
	free_split(aux);
}

void	alloc_sprites_struct(t_map *map)
{
	map->sprites = (char ***)ft_calloc(map->sprite_cnt + 1, sizeof(char **));
	map->spaux = (t_spaux *)ft_calloc(map->sprite_cnt + 1, sizeof(t_spaux));
}

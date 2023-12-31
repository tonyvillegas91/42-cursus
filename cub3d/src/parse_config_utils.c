/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:50:58 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:50:58 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

t_bool	check_if_filled(const t_map *map)
{
	return (!map->no || !map->so || !map->we
		|| !map->ea || !map->frgb || !map->crgb || !map->door
		|| map->pos_index == -1 || map->sprite_cnt == -1);
}

void	tex_filler(t_map *map, int *i, int ret)
{
	if ((ft_strncmp(map->buffer[*i], "\n", 1) == 0
			|| ft_strncmp(map->buffer[*i], "\0", 1) == 0))
		return ;
	else
	{
		ret = read_texture(&map, *i);
		if (ret == 1)
		{
			*i = fill_sprites(map, *i);
			if (*i >= dptr_len(map->buffer))
				error_ret("Error\nParser didn't find"
					"END POS or END SPRITES\n", -1);
			if (*i == -1
				|| (ft_strncmp(map->buffer[*i], ES, ft_strlen(ES)) != 0
					&& ft_strncmp(map->buffer[*i], EP, ft_strlen(EP)) != 0))
				error_ret("Error\nInvalid data on cfg\n", -1);
		}
		else if (ret == 0)
			return ;
		else
			error_ret(NULL, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:51:12 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:51:12 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	above_and_below(t_map **map, int i, int j, int x)
{
	int		og;
	char	*tmp;

	og = j;
	if (i >= dptr_len((*map)->map) || i <= 0)
		return (-1);
	tmp = (*map)->map[i];
	while (j < x)
	{
		if (tmp[j] != '1' && tmp[j] != ' ')
			return (-2);
		j++;
	}
	if (j > og)
		return (j);
	return (0);
}

int	check_surroundings(t_map **map, int i, int j)
{
	int	x;
	int	ret;

	x = j;
	while ((*map)->map[i][x] == ' ')
		x++;
	ret = above_and_below(map, i + 1, j, x);
	if (ret == -2)
		return (-1);
	ret = above_and_below(map, i - 1, j, x);
	if (ret == -2)
		return (-1);
	if (x > 1)
		return (x);
	return (j);
}

int	last_map_check(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->map[++i])
	{
		j = skip_spaces((*map)->map[i], 0);
		while ((*map)->map[i][++j] != '\n' && (*map)->map[i][j] != '\0')
		{
			if (ft_strchr("NWSE", (*map)->map[i][j]))
			{
				(*map)->p_pos[0] = (float)j;
				(*map)->p_pos[1] = (float)i;
				(*map)->start_orientation = (*map)->map[i][j];
				(*map)->map[i][j] = '0';
			}
			if ((*map)->map[i][j] == ' ')
			{
				j = check_surroundings(map, i, j);
				if (j == -1)
					return (error_ret("Error\nMap isn't closed by 1\n", 1));
			}
		}
	}
	return (0);
}

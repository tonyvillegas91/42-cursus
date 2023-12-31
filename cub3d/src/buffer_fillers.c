/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_fillers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:49:52 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:49:52 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	fill_map(t_map **map)
{
	int	i;

	i = 0;
	while ((*map)->buffer[(*map)->index])
	{
		if (ft_strncmp((*map)->buffer[(*map)->index], "\0", 1) != 0)
			break ;
		(*map)->index++;
	}
	while ((*map)->buffer[(*map)->index] && (*map)->index < ((*map)->lines))
	{
		if (!*(*map)->buffer[(*map)->index])
			break ;
		(*map)->map[i++] = ft_substr((*map)->buffer[(*map)->index],
				0, ft_strlen((*map)->buffer[(*map)->index]));
		(*map)->index++;
	}
	(*map)->map[i] = NULL;
}

int	fill_buffer(char *file, int lines, t_map *map)
{
	char	*s;
	int		fd;
	int		i;

	i = -1;
	map->buffer = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!map->buffer)
		return (1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (++i < lines)
	{
		s = ft_get_next_line(fd);
		map->buffer[i] = ft_substr(s, 0, ft_strlen(s) - 1);
		free(s);
	}
	map->buffer[i] = NULL;
	close(fd);
	return (0);
}

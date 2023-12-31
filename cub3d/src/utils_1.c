/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:51:49 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:51:49 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	free_split(map->map);
	free_split(map->buffer);
	if (map->sprites)
	{
		while (map->sprites[++i])
			free_split(map->sprites[i]);
		free(map->sprites);
	}
	i = -1;
	while (++i <= map->sprite_cnt)
		free(map->spaux[i].type);
	free(map->sprite);
	free(map->spaux);
	free(map->no);
	free(map->so);
	free(map->we);
	free(map->ea);
	free(map->door);
	free(map);
}

void	free_vars(t_vars *vars)
{
	free_map(vars->map);
	free(vars->sprite);
	free(vars->ray);
	free(vars);
}

void	free_all(t_vars *vars)
{
	int	i;
	int	j;

	mlx_destroy_image(vars->mlx, vars->minimap.img);
	mlx_destroy_image(vars->mlx, vars->mm_player.img);
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_image(vars->mlx, vars->tex[TEX_NO].img.img);
	mlx_destroy_image(vars->mlx, vars->tex[TEX_SO].img.img);
	mlx_destroy_image(vars->mlx, vars->tex[TEX_WE].img.img);
	mlx_destroy_image(vars->mlx, vars->tex[TEX_EA].img.img);
	mlx_destroy_image(vars->mlx, vars->tex[TEX_DOOR].img.img);
	i = -1;
	while (vars->sprite != NULL && vars->sprite[++i] != NULL)
	{
		j = -1;
		while (vars->sprite[i][++j] != NULL)
		{
			mlx_destroy_image(vars->mlx, vars->sprite[i][j]->img.img);
			free(vars->sprite[i][j]);
		}
		free(vars->sprite[i]);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
}

int	initialise_vars(t_vars *vars)
{
	vars->frame = -1;
	vars->sprite = NULL;
	vars->keys.w = FALSE;
	vars->keys.s = FALSE;
	vars->keys.a = FALSE;
	vars->keys.d = FALSE;
	vars->keys.c = TRUE;
	vars->keys.right_arrow = FALSE;
	vars->keys.left_arrow = FALSE;
	vars->keys.shift = FALSE;
	vars->keys.mouse_x = -1;
	player_init(vars);
	vars->ray = (t_ray *)malloc(sizeof(t_ray));
	if (vars->ray == NULL)
		perror_exit("malloc");
	return (0);
}

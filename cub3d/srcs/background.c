/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:17:17 by antville          #+#    #+#             */
/*   Updated: 2022/03/14 13:06:56 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_background(t_img bg, int ceiling, int floor)
{
	int	x;
	int	y;
	int	texture;

	y = 0;
	texture = ceiling;
	while (y < WIN_HEIGHT)
	{
		if (y == WIN_HALF)
			texture = floor;
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(&bg, x, y, texture);
			x++;
		}
		y++;
	}
}

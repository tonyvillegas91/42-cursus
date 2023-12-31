/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:50:41 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:50:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	game_loop(void *vars)
{
	if (++((t_vars *)vars)->frame >= 60)
		((t_vars *)vars)->frame = 0;
	handle_keys((t_vars *)vars);
	draw((t_vars *)vars);
	return (0);
}

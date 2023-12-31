/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:50:30 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:50:30 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	close_win(t_vars *vars)
{
	free_all(vars);
	ft_putstr_fd("Quit\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	toggle_mouse(t_vars *vars)
{
	if (vars->keys.c == TRUE)
		vars->keys.c = FALSE;
	else
		vars->keys.c = TRUE;
}

int	key_press_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_win(vars);
	else if (keycode == KEY_W)
		vars->keys.w = TRUE;
	else if (keycode == KEY_A)
		vars->keys.a = TRUE;
	else if (keycode == KEY_S)
		vars->keys.s = TRUE;
	else if (keycode == KEY_D)
		vars->keys.d = TRUE;
	else if (keycode == KEY_RIGHT)
		vars->keys.right_arrow = TRUE;
	else if (keycode == KEY_LEFT)
		vars->keys.left_arrow = TRUE;
	else if (keycode == KEY_SHIFT)
		vars->keys.shift = TRUE;
	else if (keycode == KEY_E)
		handle_door(vars);
	else if (keycode == KEY_C)
		toggle_mouse(vars);
	return (0);
}

int	key_relase_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->keys.w = FALSE;
	else if (keycode == KEY_A)
		vars->keys.a = FALSE;
	else if (keycode == KEY_S)
		vars->keys.s = FALSE;
	else if (keycode == KEY_D)
		vars->keys.d = FALSE;
	else if (keycode == KEY_RIGHT)
		vars->keys.right_arrow = FALSE;
	else if (keycode == KEY_LEFT)
		vars->keys.left_arrow = FALSE;
	else if (keycode == KEY_SHIFT)
		vars->keys.shift = FALSE;
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	float	diff_x;

	(void)y;
	vars->keys.prev_mouse_x = vars->keys.mouse_x;
	vars->keys.mouse_x = x;
	diff_x = (float)vars->keys.mouse_x - (float)vars->keys.prev_mouse_x;
	if (vars->keys.c == TRUE)
	{
		if (diff_x > 0)
			handle_look(KEY_RIGHT, vars, fabs(diff_x) / (float)MOUSE_MOD);
		else
			handle_look(KEY_LEFT, vars, fabs(diff_x) / (float)MOUSE_MOD);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:35:13 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:35:13 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

void	if_minishell(t_input *in)
{
	if (ft_strcmp(in->split_in[0], "./minishell"))
	{
		signal(SIGINT, handler2);
		signal(SIGQUIT, handler2);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	handler(int code)
{
	if (code == SIGINT)
	{
		g_exit_status = 1;
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler2(int code)
{
	if (code == SIGINT)
	{
		write(2, "\n", 1);
		g_exit_status = 130;
	}
	else if (code == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
		g_exit_status = 131;
	}
}

void	handler3(int code)
{
	if (code == SIGINT)
		exit(130);
	if (code == SIGQUIT)
		exit(131);
}

void	handler4(int code)
{
	if (code == SIGINT)
	{
		write(2, "\n", 1);
		exit(250);
	}
}

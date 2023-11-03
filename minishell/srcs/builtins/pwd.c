/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:37:56 by antville          #+#    #+#             */
/*   Updated: 2022/01/18 15:43:14 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd(t_input *in)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		pwd = ft_getenv("PWD", in);
	ft_putendl_fd(pwd, 1);
	free(pwd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:32:53 by antville          #+#    #+#             */
/*   Updated: 2024/01/03 15:32:53 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	**matrix_add_back(char **matrix, char *str)
{
	char	**out;
	int		len;
	int		i;

	i = -1;
	out = NULL;
	if (!str)
		return (matrix);
	len = matrix_len(matrix);
	out = malloc(sizeof(char *) * (len + 2));
	out[len + 1] = NULL;
	if (!out)
		return (matrix);
	while (++i < len && matrix[i] != NULL)
	{
		out[i] = ft_strdup(matrix[i]);
		if (!out[i])
		{
			free_matrix(matrix);
			free_matrix(out);
		}
	}
	out[i] = ft_strdup(str);
	free_matrix(matrix);
	return (out);
}

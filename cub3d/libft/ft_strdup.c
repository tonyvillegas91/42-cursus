/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 12:33:27 by antville          #+#    #+#             */
/*   Updated: 2021/04/15 13:02:26 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = ft_strlen(s1);
	copy = malloc(sizeof(char)* (i + 1));
	if (!copy)
		return (0);
	if (copy)
		ft_memcpy(copy, s1, i);
	copy [i] = '\0';
	return (copy);
}
/*int	main(void)
{

    char source[] = "GeeksForGeeks";

    // A copy of source is created dynamically
    // and pointer to copy is returned.
    char* target = ft_strdup(source);

    printf("%s", target);
    return 0;
}*/

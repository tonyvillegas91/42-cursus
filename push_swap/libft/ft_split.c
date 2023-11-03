/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:32:19 by antville          #+#    #+#             */
/*   Updated: 2021/04/22 12:08:53 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbofwords(char *s, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static int	ft_strlenword(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*my_free(char **tab, int i)
{
	while (i-- > 0)
	{
		free(tab[i]);
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		nb_ofwords;
	char	**tab;
	int		i;

	if (!s)
		return (0);
	nb_ofwords = ft_nbofwords((char *)s, c);
	tab = (char **)malloc((nb_ofwords + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (nb_ofwords--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[i] = ft_substr((char *)s, 0, ft_strlenword((char *)s, c));
		if (!tab[i])
			return (my_free(tab, i));
		s = s + ft_strlenword((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*int main()
{
	char *s = ":::::::::::hola::::::hola:kjkgfd:::::::\n::::::::d::::";
	char **t = ft_split(s, ':');
	printf("---------final---------%s\n", t[0]);
	printf("---------final---------%s\n", t[1]);
	printf("---------final---------%s\n", t[2]);
	printf("---------final---------%s\n", t[3]);
	printf("---------final---------%s\n", t[4]);
	printf("---------final---------%s\n", t[5]);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:56:25 by antville          #+#    #+#             */
/*   Updated: 2021/04/20 13:23:12 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsub(char *str, unsigned int start, size_t len, char const *s)
{
	int	j;

	j = 0;
	while (j < (int)len && s[j] != '\0')
	{
		str[j] = s[start];
		j++;
		start++;
	}
	str[j] = 0;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
	{
		str = malloc(1);
		if (str == NULL)
			return (0);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (0);
	ft_strsub(str, start, len, s);
	return (str);
}
/*int	main(void)
{
	char *a = "i just want this part #############";
	printf("%s\n", ft_substr(a, 5, 6));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:36:33 by antville          #+#    #+#             */
/*   Updated: 2021/06/02 11:42:10 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// Esta función libera el auxiliar pq estamos en el \0
static char	*ft_delete(char *aux)
{
	if (aux)
	{
		free(aux);
		aux = NULL;
	}
	return (aux);
}
/*Por si los bytes leidos son 0 y la cadena esta vacia, 
ahí que devolver una cadena vacia
Tambien si ha habido un error al leer el fd*/

static int	ft_return(char **line, int ret)
{
	if (ret < 0)
		return (-1);
	*line = ft_strdup("");
	return (0);
}
/*reviso la linea copiada en la auxiliar por si dentro de ella hay un \n o u
n \0, lo que sobra despues de un \n pues lo remeto en el aux y ret = 1
pq he leido algo.
Si no hay \n puede haber \0 y por eso directamente en el line meto la frase
y ret  = 0 pq hemos llegado al final por lo tanto libero el auxiliar y 
la apunto a null para saber que no hay nada dentro en la siguiente vuelta.*/

static char	*ft_print(char **line, char *aux, int *ret)
{
	int		count;
	char	*temp;

	count = 0;
	while (aux[count] != '\n' && aux[count] != '\0')
		count++;
	if (aux[count] == '\n')
	{
		*line = ft_substr(aux, 0, count);
		temp = ft_strdup(aux + (count + 1));
		free(aux);
		aux = temp;
		if (aux[0] == '\0')
			aux = ft_delete(aux);
		*ret = 1;
	}
	else
	{
		*line = ft_strdup(aux);
		free(aux);
		aux = NULL;
		*ret = 0;
	}
	return (aux);
}
/*Compruebo que no me trolean con los parametros, asigno el tamaño del buff
que va a ser el buffersize cualquier problema devuelvo menos 1
mientras los bytes leidos sean > 0 meto en el auxiliar la string que sea
sino hay nada; si hay algo le hago join con lo anterior
Si encuentro un \n en mi cadena me salgo del while, libero el buf, compruebo
cualquier problema y voy metiendo en el auxiliar las strings*/

int	get_next_line(int fd, char **line)
{
	static char	*aux[4096];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (aux[fd] == NULL)
			aux[fd] = ft_strdup(buf);
		else
			aux[fd] = ft_strjoin(aux[fd], buf);
		if (ft_strchr(aux[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFFER_SIZE);
	}
	if ((ret < 0) || (aux[fd] == NULL && ret == 0))
		return (ft_return(line, ret));
	aux[fd] = ft_print(line, aux[fd], &ret);
	return (ret);
}
/*int main(void)
{
    char    *line;
    int     fd;
    int     stat;
    fd = open("lotr.txt", O_RDONLY);
    stat = get_next_line(fd, &line);
    while (stat >= 0)
    {
        printf("%s\n", line);
		printf("---->%d<-----\n", stat);
        free(line);
        line = NULL;
        if (stat == 0)
            break ;
        stat = get_next_line(fd, &line);
    }
    free(line);
    line = NULL;
    close(fd);
    system("leaks a.out");
    return (0);
}*/

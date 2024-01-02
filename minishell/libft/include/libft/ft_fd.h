/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:47:41 by antville          #+#    #+#             */
/*   Updated: 2024/01/02 12:47:41 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_FD_H
# define FT_FD_H

// put fd
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putendl_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
void	*ft_putmem_fd(void *addr, unsigned int size, int fd);

// ft_get_next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1
# endif

char	*ft_get_next_line(int fd);

#endif

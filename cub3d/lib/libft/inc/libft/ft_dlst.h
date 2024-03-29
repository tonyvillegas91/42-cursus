/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antville <antville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:39:23 by antville          #+#    #+#             */
/*   Updated: 2023/12/31 15:39:23 by antville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_DLST_H
# define FT_DLST_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_dlist
{
	void			*data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_dlstnew(void *data);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
int		ft_dlstsize(t_dlist *dlst);
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstfirst(t_dlist *lst);
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstiter(t_dlist *dlst, void (*f)(void *));
t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *));

#endif

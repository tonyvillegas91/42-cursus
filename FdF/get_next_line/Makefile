# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antville <antville@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/09 11:46:12 by antville          #+#    #+#              #
#    Updated: 2021/06/09 11:47:35 by antville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	libgnl.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
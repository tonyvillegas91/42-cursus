NAME = libft.a

SRC =	./ft_bzero.c 		\
 		./ft_memccpy.c 		\
 		./ft_memchr.c 		\
 		./ft_memcpy.c 		\
 		./ft_memmove.c 		\
 		./ft_memset.c 		\
		./ft_memcmp.c		\
		./ft_strlen.c		\
		./ft_strlcpy.c		\
		./ft_strlcat.c		\
		./ft_strchr.c		\
		./ft_strrchr.c		\
		./ft_strnstr.c		\
		./ft_strncmp.c		\
		./ft_atoi.c			\
		./ft_isalpha.c		\
		./ft_isdigit.c		\
		./ft_isalnum.c		\
		./ft_isascii.c		\
		./ft_isprint.c		\
		./ft_toupper.c		\
		./ft_tolower.c		\
		./ft_calloc.c		\
		./ft_strdup.c		\
		./ft_putchar_fd.c	\
		./ft_putstr_fd.c	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		./ft_substr.c		\
		./ft_strjoin.c		\
		./ft_strtrim.c		\
		./ft_itoa.c			\
		./ft_split.c		\
		./ft_strmapi.c		\

SRC_B = ./ft_lstnew.c		\
		./ft_lstadd_front.c	\
		./ft_lstsize.c		\
		./ft_lstlast.c		\
		./ft_lstadd_back.c	\
		./ft_lstdelone.c	\
		./ft_lstclear.c		\
		./ft_lstiter.c		\
		./ft_lstmap.c		\

OBJS = $(SRC:.c=.o)
OBJS_B = $(SRC_B:.c=.o)
HDRS = libft.h

all: $(NAME) 

$(NAME): $(OBJS)
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: all $(OBJS_B)
	gcc -c -Wall -Wextra -Werror -I $(HDRS) $(SRC_B)
	ar rc $(NAME) $(OBJS_B)
	ranlib $(NAME)
clean:
	/bin/rm -f $(OBJS) $(OBJS_B)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

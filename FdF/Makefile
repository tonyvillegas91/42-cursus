# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antville <antville@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 14:39:12 by antville          #+#    #+#              #
#    Updated: 2023/12/31 14:39:12 by antville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COLORS
NOCOL=\033[0m
RED=\033[1;31m
YEL=\033[1;33m
ORG=\033[0;33m
GRN=\033[1;32m
DGRAY=\033[1;30m
BLU=\033[1;34m

# NAMES
NAME = fdf

LFT_NAME = libft.a

LMLX_NAME_MMS = libmlx.dylib
LMLX_NAME_MACOS_SIERRA = libmlx.a
LMLX_NAME_LINUX = libmlx_Linux.a

# MAKE
MAKE = make

# COMPILER
CC = gcc

CFLAGS = -Wall -Wextra -Werror
CCFLAGS = -Wall -Wextra -Werror

CCFLAGS += -D WIN_H=720 -D WIN_W=1280
#CCFLAGS += -D WIN_H=1080 -D WIN_W=1920

CFLAGS += -D BUFFER_SIZE=10
#CFLAGS += -D BUFFER_SIZE=500

CFLAGS += -O3
CCFLAGS += -O3

#CFLAGS += -fsanitize=address -g3
#CCFLAGS += -fsanitize=address -g3

CFLAGS += -I ./$(LFT_DIR)/inc -I ./$(LMLX_DIR) -I ./inc

LDFLAGS = -L ./

# FDF COLORS
#DCOLORS =	-D COLOR_1=0x00a0b0		\
#			-D COLOR_2=0x4f372d		\
#			-D COLOR_3=0xcc2a36		\
#			-D COLOR_4=0xeb6841		\
#			-D COLOR_5=0xedc951

CFLAGS += $(DCOLORS)
CCFLAGS += $(DCOLORS)

# LIBS
LFT = $(LFT_DIR)/$(LFT_NAME)
LMLX = $(LMLX_DIR)/$(LMLX_NAME)

# PATHS
INC_PATH = inc
SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = lib

# LIBS DIR
LFT_DIR = $(LIB_PATH)/libft

LMLX_DIR_LINUX = $(LIB_PATH)/mlx_linux
LMLX_DIR_MMS = $(LIB_PATH)/mlx_mms
LMLX_DIR_MACOS_SIERRA = $(LIB_PATH)/mlx_macos_sierra

# SOURCES
SRC_FILES =		main.c			utils.c			map_utils.c			\
				handle_args.c	mlx_main.c		mlx_hook.c			\
				draw.c			draw_utils.c	controls.c			\
				mlx_utils.c		color.c			error.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CFLAGS += -D LINUX
	LDLIBS = -lft -lmlx_Linux
	LDLIBS += -lXext -lX11 -lm -lz
	LMLX_NAME = $(LMLX_NAME_LINUX)
	LMLX_DIR = $(LMLX_DIR_LINUX)
endif
ifeq ($(UNAME_S),Darwin)
	CFLAGS += -D OSX
#	########## SHARED VARS       ##########
	CCFLAGS += -framework OpenGL -framework AppKit
	LDLIBS = -lft -lmlx
#	########## mlx_mms           ##########
#	LMLX_NAME = $(LMLX_NAME_MMS)
#	LMLX_DIR = $(LMLX_DIR_MMS)
#	########## mlx_macos_sierra  ##########
	LMLX_NAME = $(LMLX_NAME_MACOS_SIERRA)
	LMLX_DIR = $(LMLX_DIR_MACOS_SIERRA)
endif

.PHONY: all clean fclean re norm

all: $(NAME) $(CHECKER_NAME)

$(NAME): $(LFT_NAME) $(LMLX_NAME) $(OBJ)
	$(CC) $^ -o $@ $(CCFLAGS) $(LDFLAGS) $(LDLIBS)

$(LFT_NAME):
	$(MAKE) all -sC $(LFT_DIR)
	cp $(LFT) $(LFT_NAME)

$(LMLX_NAME):
	$(MAKE) all -sC $(LMLX_DIR) 2> /dev/null
	cp $(LMLX) $(LMLX_NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH) 2> /dev/null

clean:
	$(MAKE) clean -sC $(LFT_DIR)
	$(MAKE) clean -sC $(LMLX_DIR)
	rm -rf $(LFT_NAME)
	rm -rf $(LMLX_NAME)
	rm -rf $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -sC $(LFT_DIR)
	rm -rf $(NAME)

re: fclean all

norm:
	@printf "\n${GRN}##########${YEL} NORMINETTE ${GRN}##########${NOCOL}\n"
	@printf "\n${GRN}LIBFT:${BLU}\n\n"
	@norminette $(LFT_DIR)
	@printf "\n${GRN}FDF:${BLU}\n\n"
	@norminette $(INC_PATH)
	@norminette $(SRC_PATH)
	@printf "${NOCOL}"

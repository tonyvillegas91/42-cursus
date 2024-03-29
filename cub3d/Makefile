# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antville <antville@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 15:52:03 by antville          #+#    #+#              #
#    Updated: 2023/12/31 15:52:03 by antville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



# **************************************************************************** #
#                                     VARS                                     #
# **************************************************************************** #

# COLORS
NOCOL=\033[0m
RED=\033[31m
GRN=\033[32m
YEL=\033[33m
BLU=\033[34m
MAG=\033[35m
CYN=\033[36m

# OS
UNAME_S := $(shell uname -s)

# **************************************************************************** #
#                                   PROGRAM                                    #
# **************************************************************************** #

NAME = cub3D

LFT_NAME = libft.a

LMLX_NAME_MMS = libmlx.dylib
LMLX_NAME_MACOS_SIERRA = libmlx.a
LMLX_NAME_LINUX = libmlx_Linux.a

# **************************************************************************** #
#                                   COMPILER                                   #
# **************************************************************************** #

# MAKE
MAKE = make

# COMPILER
CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGS += -D NAME=\"$(NAME)\"
CFLAGS += -D WIN_H=720 -D WIN_W=1280
#CFLAGS += -D WIN_H=1080 -D WIN_W=1920

CFLAGS += -D BUFFER_SIZE=10

#CFLAGS += -O3

CCFLAGS = $(CFLAGS)

# **************************************************************************** #
#                                    FLAGS                                     #
# **************************************************************************** #

CFLAGS += -I ./$(LFT_DIR)/inc -I ./$(LMLX_DIR) -I ./$(INC_PATH)

# **************************************************************************** #
#                                    PATHS                                     #
# **************************************************************************** #

INC_PATH = inc
SRC_PATH = src
OBJ_PATH = obj
LIB_PATH = lib

# **************************************************************************** #
#                                     LIBS                                     #
# **************************************************************************** #

# LIB FLAGS
LDFLAGS = -L ./

# LIBS
LFT = $(LFT_DIR)/$(LFT_NAME)
LMLX = $(LMLX_DIR)/$(LMLX_NAME)

# LIBS DIR
LFT_DIR = $(LIB_PATH)/libft

LMLX_DIR_LINUX = $(LIB_PATH)/mlx_linux
LMLX_DIR_MMS = $(LIB_PATH)/mlx_mms
LMLX_DIR_MACOS_SIERRA = $(LIB_PATH)/mlx_macos_sierra

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

# SOURCES MAIN
SRC_FILES =		main.c				error.c				utils_1.c				\
				utils_2.c

# SOURCES PARSE
SRC_FILES +=	parser_main.c		parse_map.c			parse_config.c			\
				parser_utils.c		buffer_fillers.c	parse_map2.c			\
				parser_sprite_utils.c parse_config_utils.c

# SOURCES MINILIBX
SRC_FILES +=	mlx_main.c				mlx_hook.c			mlx_init.c			\
				mlx_utils.c				mlx_loop.c			mlx_controls.c		\
				mlx_textures.c			minimap.c			minimap_utils.c		\
				player.c				draw.c				raycast_wall.c		\
				raycast_wall_utils.c	raycast_sprite.c

SRC = $(addprefix $(SRC_PATH)/, $(SRC_FILES))

OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_FILES))

# **************************************************************************** #
#                                CROSS COMPILE                                 #
# **************************************************************************** #

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
	CFLAGS += -O3
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

# **************************************************************************** #
#                                    RULES                                     #
# **************************************************************************** #

# ALL
PHONY := all
all: $(NAME)

# NAME
$(NAME): $(LFT_NAME) $(LMLX_NAME) $(OBJ)
	@printf "\n${YEL}LINKING:${NOCOL}\n"
	@printf "${BLU}"
	$(CC) $^ -o $@ $(CCFLAGS) $(LDFLAGS) $(LDLIBS)
	@printf "${NOCOL}"
	@printf "\n${GRN}SUCCESS!${NOCOL}\n"
	@printf "${CYN}type \"./cub3D\" to start!${NOCOL}\n"

# SANITIZE ADDRESS
PHONY += sanitize
ifeq ($(UNAME_S),Linux)
sanitize: CFLAGS += -pedantic -g3 -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=bounds -fsanitize=null
endif
ifeq ($(UNAME_S),Darwin)
sanitize: CFLAGS += -pedantic -g3 -fsanitize=address
endif
sanitize: $(NAME)

# SANITIZE THREAD
PHONY += thread
thread: CFLAGS += -g3 -fsanitize=thread
thread: $(NAME)

# LIBRARIES
$(LFT_NAME): $(LFT)
	@printf "${MAG}"
	cp $(LFT) $(LFT_NAME)
	@printf "${NOCOL}\n"
$(LFT):
	@printf "${YEL}LIBFT:${NOCOL}\n"
	@printf "${MAG}"
	$(MAKE) all -sC $(LFT_DIR)
	@printf "${NOCOL}"

$(LMLX_NAME): $(LMLX)
	@printf "${MAG}"
	cp $(LMLX) $(LMLX_NAME)
	@printf "${NOCOL}\n"
$(LMLX):
	@printf "${YEL}MINILIBX:${NOCOL}\n"
	@printf "${MAG}"
	$(MAKE) all -sC $(LMLX_DIR) 2> /dev/null
	@printf "${NOCOL}"

# OBJ
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@printf "${BLU}"
	$(CC) $(CFLAGS) -c $< -o $@
	@printf "${NOCOL}"

# DEP
$(OBJ_PATH)/%.d: $(SRC_PATH)/%.c | $(OBJ_PATH)
	@set -e; rm -f $@
	$(CC) -M $(CFLAGS) $< > $@.$$$$
	rm -f $@.$$$$

# OBJ DIRS
$(OBJ_PATH):
	@printf "${MAG}"
	mkdir -p $(OBJ_PATH)
	@printf "${NOCOL}"

# CLEAN
PHONY += clean
clean:
	@printf "${RED}"
	$(MAKE) clean -sC $(LFT_DIR)
	@printf "${RED}"
	rm -rf $(LFT_NAME)
	rm -rf $(LMLX_NAME)
	rm -rf $(OBJ_PATH)
	@printf "${NOCOL}"

# FULL CLEAN
PHONY += fclean
fclean: clean
	@printf "${RED}"
	$(MAKE) fclean -sC $(LFT_DIR)
	@printf "${RED}"
	$(MAKE) clean -sC $(LMLX_DIR)
	@printf "${RED}"
	rm -rf $(NAME)
	@printf "${NOCOL}"

# RE
PHONY += re
re: fclean all

# NORMINETTE
PHONY += norme
norme:
	@printf "\n${GRN}##########${YEL} NORMINETTE ${GRN}##########${NOCOL}\n"
	@printf "\n${GRN}LIBFT:${BLU}\n\n"
	@norminette $(LFT_DIR)
	@printf "\n${GRN}CUB3D:${BLU}\n\n"
	@norminette $(INC_PATH)
	@norminette $(SRC_PATH)
	@printf "${NOCOL}"

.PHONY: $(PHONY)

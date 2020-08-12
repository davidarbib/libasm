# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 14:53:36 by darbib            #+#    #+#              #
#    Updated: 2020/08/12 23:13:38 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
#CFLAGS = -Wall -Wextra -Werror -framework OpenGL -framework AppKit
ASM = nasm
FLAGS = -f elf64 

ifeq ($(DEBUG), 1)
	FLAGS += -g -F dwarf
endif

# ------------------------------------------------------------------------------

LIB_DIR = /usr/lib/
OBJ_DIR = ./objs/
SRC_DIR = ./srcs/

# ------------------------------------------------------------------------------

OBJ = $(SRC:%.s=$(OBJ_DIR)%.o)

SRC = ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s

# ------------------------------------------------------------------------------

vpath %.s $(SRC_DIR)

.PHONY: all clean fclean re

# ------------------------------------------------------------------------------

all : $(NAME)

bonus : $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

$(OBJ_DIR)%.o : $(SRC_DIR)%.s
	@mkdir -p objs
	$(ASM) $(FLAGS) $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all

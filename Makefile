# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 14:53:36 by darbib            #+#    #+#              #
#    Updated: 2020/08/20 16:59:07 by darbib           ###   ########.fr        #
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
OBJ_BONUS = $(SRC_BONUS:%.s=$(OBJ_DIR)%.o)

SRC = ft_read.s \
	ft_strcmp.s \
	ft_strcpy.s \
	ft_strdup.s \
	ft_strlen.s \
	ft_write.s

SRC_BONUS = ft_atoi_base.s \
	ft_list_push_front.s \
	ft_list_sort.s \
	ft_list_size.s

# ------------------------------------------------------------------------------

vpath %.s $(SRC_DIR)

.PHONY: all clean fclean re

# ------------------------------------------------------------------------------

all : $(NAME)

test : all
	gcc print.c $(NAME) -o print
	./print

test_bonus : bonus
	gcc print.c $(NAME) -o print
	./print

bonus : $(NAME) $(OBJ_BONUS)
	@ar r $(NAME) $(OBJ_BONUS)
	@echo $(NAME) builded with bonuses !

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@echo $@ builded !

$(OBJ_DIR)%.o : $(SRC_DIR)%.s
	@mkdir -p objs
	@echo compiling $<
	@$(ASM) $(FLAGS) $< -o $@

clean :
	@echo Cleaning objs...
	@rm -rf $(OBJ_DIR)
	@echo ...done

fclean : clean
	@echo Total cleaning...
	@rm -f $(NAME)
	@rm -f print.o
	@rm -f print
	@echo ...done

re : fclean all

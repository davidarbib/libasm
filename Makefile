# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darbib <darbib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 14:53:36 by darbib            #+#    #+#              #
#    Updated: 2020/08/22 02:13:51 by darbib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
ASM = nasm
FLAGS = -f elf64 
CC = clang

ifeq ($(DEBUG), 1)
	FLAGS += -g -F dwarf
	LFLAGS += -g3
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
	ft_list_remove_if.s \
	ft_list_size.s

# ------------------------------------------------------------------------------

vpath %.s $(SRC_DIR)

.PHONY: all clean fclean re test test_bonus bonus

# ------------------------------------------------------------------------------

all : $(NAME)

test : $(NAME)
	@echo "Testing executable generated..."
	@$(CC) $(LFLAGS) print.c $(NAME) -o $@

test_bonus : bonus
	@echo "Bonus testing executable generated..."
	@$(CC) $(LFLAGS) print_bonus.c $(NAME) -o $@

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
	@rm -f test
	@rm -f test_bonus
	@echo ...done

re : fclean all

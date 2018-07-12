# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 09:34:42 by rpetluk           #+#    #+#              #
#    Updated: 2018/07/08 14:32:22 by rpetluk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_DIR	:= libft

include	libft/Libft.mk

NAME := lem-in

GCC := gcc -Wall -Wextra -Werror

DEPS	:= lem-in.h

OBJS_DIR := obj

INCLUDES := -I.

OBJECTS_F :=	algorithm.o			\
           		creat_list.o		\
           		lem-in.o			\
           		read_instruction.o	\
           		validate_ants.o		\
           		validate_move.o		\
           		validate_room.o

OBJECTS  := $(OBJECTS_F:%.o=$(OBJS_DIR)/%.o)

all : $(NAME)

$(NAME): $(FT_NAME) $(OBJECTS)
	@$(GCC) -o $(NAME) $(OBJECTS) $(FT_NAME)

$(FT_NAME): $(FT_SRCS) $(FT_DEPS)
	@$(MAKE) -C libft

$(OBJECTS): |$(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c $(DEPS)
	@ $(GCC) -o $@ -c $< $(INCLUDES)

$(OBJS_DIR):
	@mkdir $@

clean:
	@ $(MAKE) clean -C $(FT_DIR)
	@ rm -rf $(OBJS_DIR)

fclean : clean
	@ $(MAKE) fclean -C $(FT_DIR)
	@ rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpetluk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 09:34:42 by rpetluk           #+#    #+#              #
#    Updated: 2018/04/04 10:47:38 by rpetluk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_DIR	:= libft

include	libft/Libft.mk

NAME = push_swap

CR_NAME = checker


GCC = gcc -Wall -Wextra -Werror

DEPS	:= push_swap.h checker.h
INCLUDES = -I.

OBJECTS = 	bonus.o         \
            bonus_colour.o

CR_OBJ = 	checker.o       \
            lib_check.o     \
            ft_check_swap.o \
            comands.o

PS_OBJ =    push_swap.o     \
            lib_push_swap.o \
            swap.o          \
            median.o        \
            qsort_a.o       \
            qsort_b.o       \
            lib_push_swap_a.o   \
            sort3.o         \

all : $(CR_NAME) $(NAME)

$(NAME): $(FT_NAME) $(OBJECTS) $(PS_OBJ)
	@$(GCC) -o $(NAME) $(OBJECTS) $(PS_OBJ) $(FT_NAME)

$(CR_NAME): $(FT_NAME) $(OBJECTS) $(CR_OBJ)
	@$(GCC) -o $(CR_NAME) $(OBJECTS) $(CR_OBJ) $(FT_NAME)

$(FT_NAME): $(FT_OBJS) $(FT_DEPS)
	@$(MAKE) -C libft

%.o : %.c $(DEPS)
	@ $(GCC) -o $@ -c $< $(INCLUDES)

clean :
	@ $(MAKE) clean -C $(FT_DIR)
	@ rm -rf $(OBJECTS) $(PS_OBJ) $(CR_OBJ)

fclean : clean
	@ $(MAKE) fclean -C $(FT_DIR)
	@ rm -rf $(NAME) $(CR_NAME)

re : fclean all

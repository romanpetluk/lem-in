include	Libft.mk

GCC = gcc -Wall -Wextra -Werror

INCLUDES = -I.

all : $(FT_NAME)

$(FT_NAME) : $(FT_OBJS)
	@ ar rc $(FT_NAME) $?
	@ ranlib $(FT_NAME)

%.o : %.c $(FT_DEPS)
	@ $(GCC) -o $@ -c $< $(INCLUDES)

clean :
	@ rm -rf $(FT_OBJS)

fclean : clean
	@ rm -rf $(FT_NAME)

re : fclean all

NAME = libft.a

SRC_LIBFT_MANDATORY = ft_atoi.c

SRCS = $(SRC_LIBFT_MANDATORY)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

OBJ_DIR = obj/
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c minitalk.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

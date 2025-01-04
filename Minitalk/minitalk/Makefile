NAME_SERVER = server
NAME_CLIENT = client

VPATH = src/

SRC_SERVER = server.c
SRC_CLIENT = client.c

HEADER = minitalk.h

LIBFT = src
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBS = -L $(LIBFT) -lft

OBJ_DIR = obj/
OBJ_SERVER = $(SRC_SERVER:%.c=$(OBJ_DIR)/%.o)
OBJ_CLIENT = $(SRC_CLIENT:%.c=$(OBJ_DIR)/%.o)

RM = rm -rf

all : $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBS) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBS) -o $(NAME_CLIENT)

$(OBJ_DIR)/%.o : %.c minitalk.h
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)
	$(MAKE) -C src clean

fclean : clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C src fclean

re : fclean all

.PHONY : all clean fclean re


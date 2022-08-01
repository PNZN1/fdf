# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/31 08:38:57 by pniezen       #+#    #+#                  #
#    Updated: 2022/08/01 15:23:31 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./lib/MLX42/include/ ./lib/libft/include/ ./lib/getnextline/include/

LIBMLX_PATH = ./lib/MLX42/
LIBFT_PATH = ./lib/libft/
LIB_GETNEXTLINE_PATH = ./lib/getnextline/

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

SRC_NAME = $(shell ls $(SRC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
LIBMLX_NAME = libmlx42.a
LIBFT_NAME = libft.a
GETNEXTLINE_NAME = get_next_line.a

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX_PATH)$(LIBMLX_NAME) $(LIBFT_PATH)$(LIBFT_NAME) $(LIB_GETNEXTLINE_PATH)$(GETNEXTLINE_NAME)
# LIB = -lglfw -L /usr/local/Cellar/glfw/3.3.7/lib/ $(LIBMLX_PATH)$(LIBMLX_NAME) $(LIBFT_PATH)$(LIBFT_NAME) $(LIB_GETNEXTLINE_PATH)$(GETNEXTLINE_NAME)

BOLD = \033[1m
GREEN = \033[32;1m
RED	= \033[31;1m
YELLOW	= \033[33;1m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBMLX_PATH)
	@make -C $(LIBFT_PATH)
	@make -C $(LIB_GETNEXTLINE_PATH)
	@$(CC) $(CFLAGS) $(LIB) $(INC) $(OBJ) -o $(NAME) && printf "$(YELLOW)$(BOLD)\rBuild $(NAME)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./include/fdf.h
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

cleanlib:
	@make -C $(LIBMLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIB_GETNEXTLINE_PATH) clean

fcleanlib:
	@make -C $(LIBMLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIB_GETNEXTLINE_PATH) fclean

clean: cleanlib
	@echo "$(RED)Cleaning$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean fcleanlib
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all


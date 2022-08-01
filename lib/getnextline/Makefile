# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/08 13:54:34 by pniezen       #+#    #+#                  #
#    Updated: 2022/06/29 14:36:55 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

NAME = get_next_line.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_NAME = $(shell ls $(SRC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

BOLD = \033[1m
GREEN = \033[32;1m
RED	= \033[31;1m
YELLOW	= \033[33;1m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME) && printf "$(YELLOW)$(BOLD)\rBuild $(NAME)\r\e[35C[OK]\n$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./include/get_next_line.h
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -D BUFFER_SIZE=20 -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

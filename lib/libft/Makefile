# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/03/08 13:54:34 by pniezen       #+#    #+#                  #
#    Updated: 2022/06/29 14:38:18 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_NAME = $(shell ls $(SRC_PATH))
# SRC_NAME = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
# ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memcmp.c\
# ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strnstr.c\
# ft_strncmp.c ft_memchr.c ft_strlcpy.c ft_strlcat.c ft_atoi.c\
# ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
# ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c\
# ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
# ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
# ft_lstiter_bonus.c ft_lstmap_bonus.c

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

$(OBJ_PATH)%.o: $(SRC_PATH)%.c ./include/libft.h
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $< && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

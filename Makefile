# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rick <rick@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 22:55:30 by ojessi            #+#    #+#              #
#    Updated: 2020/06/03 18:20:18 by rick             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = test

ID = $(shell id -un)
CC =	gcc
FLAGS =	-g # -Wall -Wextra -Werror
LIBRARIES =	-L $(LIBFT_DIR) -lft
INCLUDES =	-I $(HEADERS_DIR) -I $(LIBFT_HEADERS)

# LIBFT
LIBFT_DIR =	./libft
#LIBFT =		$(LIBFT_DIR)libft.a
LIBFT = ./libft/libft.a
LIBFT_HEADERS =	$(LIBFT_DIR)

#HEADERS
HEADERS_LIST =	ft_printf.h
HEADERS_DIR =	./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

#SOURCES
SRC_DIR =	./srcs/

SRC_LIST =	f1.c \
			f2.c \
			flags.c \
			initialization.c \
			main.c \
			mods.c \
			precision.c \
			print_values.c \
			types_csp.c \
			types_dioux.c \
			width.c \
			test.c \
			utils.c \

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

#OBJECTS
OBJ_DIR = obj/
OBJ_L = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_L))

# COLORS

GREEN =	\033[0;32m
RED =	\033[0;31m
RESET =	\033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(INCLUDES) $(OBJ) $(LIBRARIES)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)creating $(LIBFT)...$(RESET)"
	@make -C $(LIBFT_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@make fclean
	@make all
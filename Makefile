# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msalembe <msalembe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 10:18:39 by msalembe          #+#    #+#              #
#    Updated: 2024/09/24 18:19:31 by msalembe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = minishell.c src/lib.c src/lib_utils.c src/check.c \
 		src/actions.c src/mini_functions.c src/lib_utils_2.c \
		src/actions_utils.c

CC = cc
FLAGS = -Wall -Werror -Wextra




OBJ = $(SRC:.c=.o)

BOLD_PURPLE = \033[1;35m
BOLD_CYAN   = \033[1;36m
BOLD_YELLOW = \033[1;33m
NO_COLOR    = \033[0m

# ------------------------------ Mensagens ------------------------------

COMP_START  = printf "🚧 $(BOLD_YELLOW)Make: $(NO_COLOR) Iniciando a Compilação...\n$(NO_COLOR)"
SERV_READY  = printf "🗿 $(BOLD_CYAN)Shell Pronto!\n$(NO_COLOR)"

# ----------------------------- BONUS ------------------------------------

CLEANED     = printf "💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removendo todos \".o\" files \n$(NO_COLOR)"
FCLEANED    = printf "🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removendo os Executáveis \n$(NO_COLOR)"

# ------------------------------ Regras ------------------------------

all: $(NAME)

$(NAME): $(OBJ)
	@$(COMP_START)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -lreadline
	@$(SERV_READY)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@$(CLEANED)

fclean: clean
	@rm -rf $(NAME)
	@$(FCLEANED)

re: fclean all

.PHONY: all clean fclean re
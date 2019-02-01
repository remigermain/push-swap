# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/02/01 20:21:41 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = push_swap

#CFLAGS = -Wall -Werror -Wextra

INCLUDE = -Iincludes

HEADER = push_swap.h

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

DSRC = srcs/
DOBJ = obj/
ALL_D = $(DSRC)

DHEADER = includes/

CSRC = $(addprefix $(DSRC),$(SRC))
COBJ = $(addprefix $(DOBJ),$(OBJ))
CHEADER = $(addprefix $(DHEADER),$(HEADER))

# *****************************************************************************#
# 								ALL  SCRS									   #
# *****************************************************************************#

SRC = main.c check_arg.c struct_init.c ps_algo.c ps_instruction.c \
		utils.c ps_debug.c

COUNT = "1"
SPACE = "            "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

print_libft : 
	@printf	"\n\033[34m"
	@echo "	    [PUSH_SWAP]     "
	@echo "\033[0m\n\n"

print_norme : 
	@printf	"\n\033[34m"
	@echo $(SPACE)" _        _______  _______  _______ "
	@echo $(SPACE)"( (    /|(  ___  )(  ____ )(       )"
	@echo $(SPACE)"|  \  ( || (   ) || (    )|| () () |"
	@echo $(SPACE)"|   \ | || |   | || (____)|| || || |"
	@echo $(SPACE)"| (\ \) || |   | ||     __)| |(_)| |"
	@echo $(SPACE)"| | \   || |   | || (\ (   | |   | |"
	@echo $(SPACE)"| )  \  || (___) || ) \ \__| )   ( |"
	@echo $(SPACE)"|/    )_)(_______)|/   \__/|/     \|\n"
	@echo "\033[0m\n"


all: print_libft $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[34mNothing are changed !\033[0m"; \
	fi

$(NAME): $(COBJ)
	@make -C libft/ all
	@make -C push_swap_checker/ all
	@echo $(SPACE)"\033[JCompilation des Objects \033[38;5;326mterminer\033[0m"
	@echo $(SPACE)"Compilation de la library \033[34m" $(NAME) "\033[0m"
	@gcc $(COBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER)
	@$(eval COUNT = "0")
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"compilation de la fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: print_libft
	@rm -rf $(DOBJ)
	@make -C libft/ clean
	@make -C push_swap_checker/ clean
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C push_swap_checker/ fclean
	@echo $(SPACE)"Suppresion de la library \033[38;5;265m"$(NAME) "\033[0m"

re: fclean all

norme : print_norme
	@echo $(SPACE)"waiting ..."
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

norme_all : norme print_norme
	@make -C libft/ norme
	@make -C push_swap_checker/ norme
.PHONY: default all clean fclean re norme print_libft print_norme

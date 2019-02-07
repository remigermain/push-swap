# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/02/07 11:18:05 by rgermain    ###    #+. /#+    ###.fr      #
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

SRC = main.c check_arg.c struct_init.c ps_algo.c \
		ps_interact.c utils.c ps_debug.c \
		ps_instruct_push.c ps_instruct_revrotate.c \
		ps_instruct_rotate.c ps_instruct_swap.c 

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')
#	@printf	"\n\033[47m  \033[0m\n"

print_name : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                    [    PUSH_SWAP     ]             "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"

print_norme : 
	@printf "\n----------------------------------------------------------------------\n\n\033[37m"
	@printf	" \033[47m  \033[0m\033[37m                 [    PUSH_SWAP NORME     ]          "
	@printf "         \033[0m  \033[47m  \033[0m\n"
	@printf	"\n----------------------------------------------------------------------\n\n"


all: LIBFT_M PSCHECKER_M print_name $(NAME)
	@if [ $(COUNT) = "1" ]; then \
		echo $(SPACE)"\033[1;34m   Nothing are changed !\033[0m"; \
	fi

LIBFT_M : 
	@make -C libft/ all

PSCHECKER_M :
	@make -C push_swap_checker/ all

$(NAME): $(COBJ)
	@echo $(SPACE)"\033[JCompilation des Objects \033[38;5;326mterminer\033[0m"
	@echo $(SPACE)"Compilation de la library \033[34m" $(NAME) "\033[0m"
	@gcc $(COBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER)
	@$(eval COUNT = "0")
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"compilation de la fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: print_name
	@rm -rf $(DOBJ)
	@make -C libft/ clean
	@make -C push_swap_checker/ clean
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

clean_f: print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

fclean: clean_f
	@rm -f $(NAME)
	@make -C libft/ fclean
	@make -C push_swap_checker/ fclean
	@echo $(SPACE)"Suppresion de la library \033[38;5;265m"$(NAME) "\033[0m"

re: fclean all

norme : print_name print_norme
	@echo $(SPACE)"waiting \033[5m ...\033[0m"
	@sleep 2
	@echo "\033[0m\033[K\033[1A"$(SPACE) $(SPACE) $(SPACE)
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

norme_all : norme print_norme
	@make -C libft/ norme
	@make -C push_swap_checker/ norme
.PHONY: default all clean fclean re norme print_libft print_norme

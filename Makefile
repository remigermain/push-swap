# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 15:39:03 by rgermain     #+#   ##    ##    #+#        #
#    Updated: 2019/02/18 14:21:53 by rgermain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = push_swap
TYPE = "de l'executable"

LIBFT_M : 
	@make -C libft/ all
LIBFT_C : 
	@make -C libft/ clean
LIBFT_FC : 
	@make -C libft/ fclean
LIBFT_N : 
	@make -C libft/ norme
LIBFT_R : 
	@make -C libft/ re

PSCHECKER_M :
	@make -C checker_ps/ all
PSCHECKER_C :
	@make -C checker_ps/ clean
PSCHECKER_FC :
	@make -C checker_ps/ fclean
PSCHECKER_N :
	@make -C checker_ps/ norme
PSCHECKER_R :
	@make -C checker_ps/ re

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

SRC = main.c check_arg.c ps_algo.c \
		utils.c ps_algo_find.c ps_algo_find2.c ps_algo_sort.c \
		ps_instruct_push.c ps_instruct_revrotate.c \
		ps_instruct_rotate.c ps_instruct_swap.c

COUNT = "1"
SPACE = "                    "
.DEFAULT_GOAL := all
ESC = $(shell printf '\033')

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

$(NAME): $(COBJ)
	@echo $(SPACE)"\033[JCompilation des Objects \033[38;5;326mterminer\033[0m"
	@echo $(SPACE)"Compilation" $(TYPE) "\033[34m" $(NAME) "\033[0m"
	@gcc $(COBJ) $(CFLAGS) $(LIBFT) -o $(NAME)

$(DOBJ)%.o : $(DSRC)%.c $(CHEADER) $(LIBFT)
	@$(eval COUNT = "0")
	@mkdir -p $(DOBJ)
	@mkdir -p $(addprefix $(DOBJ), $(ALL_D))
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo $(SPACE)"compilation de la fonction \033[38;5;326m"$< "\033[0m\033[K\033[1A"

clean: LIBFT_C PSCHECKER_C print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

clean_f: print_name
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"

fclean: LIBFT_FC PSCHECKER_FC clean_f
	@rm -f $(NAME)
	@echo $(SPACE)"Suppresion "$(TYPE) "\033[38;5;265m"$(NAME) "\033[0m"

re_clean:
	@rm -rf $(DOBJ)
	@echo $(SPACE)"Suppresion des \033[38;5;265mobjects\033[0m"
	@rm -f $(NAME)
	@echo $(SPACE)"Suppresion "$(TYPE) "\033[38;5;265m"$(NAME) "\033[0m"

re: LIBFT_R PSCHECKER_R re_clean print_name $(NAME)

norme : print_norme
	@echo $(SPACE)"waiting \033[5m ...\033[0m"
	@sleep 1
	@echo "\033[0m\033[K\033[1A"$(SPACE) $(SPACE) $(SPACE) 
	@norminette $(CSRC) $(CHEADER) | sed "s,Norme,${ESC}[38;5;326m&${ESC}[0m," | sed "s/Error/  Error/g" | sed "s,Error,${ESC}[31m&${ESC}[0m,"

normeall : LIBFT_N PSCHECKER_N norme print_norme

.PHONY: default all fclean clean_f fclean re re_clean norme normeall print_norme print_name

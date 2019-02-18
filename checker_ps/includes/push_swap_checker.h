/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/18 14:17:21 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
# include "../../libft/includes/libft.h"

typedef struct	s_puswc
{
	int		*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
	int		*tri;
	int		instruction;
	int		fd;
	int		time;
	char	visu;
}				t_puswc;

/*
**----------------------------------------------------------------------
**					check arg
**----------------------------------------------------------------------
*/
/*
** check_arg.c
*/
int				check_arg(char **argv);
/*
**	ps_checker.c
*/
int				ps_checker(t_puswc *lst);
/*
**----------------------------------------------------------------------
**					instruction
**----------------------------------------------------------------------
*/
/*
**	ps_instruction_swap.c
*/
void			swap_a(t_puswc *lst);
void			swap_b(t_puswc *lst);
void			swap_ab(t_puswc *lst);
/*
**	ps_instruction_rotate.c
*/
void			push_a(t_puswc *lst);
void			push_b(t_puswc *lst);
/*
**	ps_instruction_rotate.c
*/
void			rotate_a(t_puswc *lst);
void			rotate_b(t_puswc *lst);
void			rotate_ab(t_puswc *lst);
/*
**	ps_instruction_revrotate.c
*/
void			rev_rotate_a(t_puswc *lst);
void			rev_rotate_b(t_puswc *lst);
void			rev_rotate_ab(t_puswc *lst);

/*
**----------------------------------------------------------------------
**					visu && interactive
**----------------------------------------------------------------------
*/
/*
**	ps_interact.c
*/
int				ps_interact(t_puswc *lst, int ret);
/*
**	ps_interact_visu.c
*/
void			ps_ivisu(t_puswc *lst);
/*
**	ps_visu.c
*/
void			ps_visu(t_puswc *lst, int j);

/*
**----------------------------------------------------------------------
**					visu && sturct init
**----------------------------------------------------------------------
*/
/*
**   utils.c
*/
void			ps_final_check(t_puswc *lst);
int				ft_issort(t_puswc *lst);
void			ps_error(t_puswc *lst);
void			ps_free(t_puswc *lst);
/*
**	struct_init.c
*/
t_puswc			*ps_struct_init(int argc, char **argv);
#endif

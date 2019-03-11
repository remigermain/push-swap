/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 11:21:08 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"
# define PS_BUFFSIZE 10

typedef struct	s_pusw
{
	int		*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
	int		pivot;
	int		max;
	int		max_n;
	char	ps_buff[PS_BUFFSIZE];
	int		ps_count;
}				t_pusw;

/*
**----------------------------------------------------------------------
**							check arg
**----------------------------------------------------------------------
*/
/*
**	check_arg.c
*/
int				check_arg(char **argv);

/*
**----------------------------------------------------------------------
**							algo && utils_algo
**----------------------------------------------------------------------
*/
/*
**	ps_algo.c
*/
void			ps_algo(t_pusw *lst);
/*
**	ps_algo_find.c
*/
int				find_sens_pivot(t_pusw *lst);
void			find_pivot(t_pusw *lst);
int				find_sens(t_pusw *lst, int max);
int				find_sens_fin(t_pusw *lst);
/*
**	ps_algo_find2.c
*/
int				find_next_max(int *stack, int len, int tmp);
int				find_next_min(int *stack, int len, int tmp);
int				find_max(int *stack, int len);
int				find_min(int *stack, int len);
int				find_nb(int *stack, int len, int nb);
/*
** ps_algo_sort.c
*/
int				ft_issort(t_pusw *lst);
int				sort_realstack_a(t_pusw *lst);
int				sort_stack_a(t_pusw *lst);

/*
**----------------------------------------------------------------------
**							all instructions
**----------------------------------------------------------------------
*/
/*
** ps_instruction_swap.c
*/
void			swap_a(t_pusw *lst);
void			swap_b(t_pusw *lst);
void			swap_ab(t_pusw *lst);
/*
** ps_instruction_push.c
*/
void			push_a(t_pusw *lst);
void			push_b(t_pusw *lst);
/*
** ps_instruction_rotate.c
*/
void			rotate_a(t_pusw *lst);
void			rotate_b(t_pusw *lst);
void			rotate_ab(t_pusw *lst);
/*
** ps_instruction_revrotate.c
*/
void			rev_rotate_a(t_pusw *lst);
void			rev_rotate_b(t_pusw *lst);
void			rev_rotate_ab(t_pusw *lst);

/*
**----------------------------------------------------------------------
**							utils
**----------------------------------------------------------------------
*/
/*
**	utils.c
*/
void			ps_putbuff(t_pusw *lst, char *str, char len);
void			ps_error(t_pusw *lst);
void			ps_free(t_pusw *lst);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 15:39:10 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

typedef struct	s_pusw
{
	int		*stack_a;
	int		len_a;
	int		*stack_b;
	int		len_b;
	size_t	instruction;
	int		med;
	int		max;
	int		max_n;
	int		max_nn;
	char	visu;
	int		time;
}				t_pusw;

/*
**----------------------------------------------------------------------
**
**							check arg && init struct
**----------------------------------------------------------------------
*/
int				check_arg(char **argv);

/*
**----------------------------------------------------------------------
**
**								algo
**----------------------------------------------------------------------
*/
void			ps_algo(t_pusw *lst);

int				sort_realstack_a(t_pusw *lst);
int				sort_realstack_a2(t_pusw *lst);
int				sort_stack_a(t_pusw *lst);
int				sort_stack_b(t_pusw *lst);
int				find_next_max(int *stack, int len, int tmp);
int				find_next_min(int *stack, int len, int tmp);
int				find_max(int *stack, int len);
int				find_min(int *stack, int len);
int				find_med(int *stack, int len);
int				find_nb(int *stack, int len, int nb);
int				find_sens(t_pusw *lst, int max);
int				find_midsens(t_pusw *lst);
void			find_mid_med(t_pusw *lst);
int				find_sens2(t_pusw *lst);

/*
**----------------------------------------------------------------------
**
**							all instructions
**----------------------------------------------------------------------
*/
void			swap_a(t_pusw *lst);
void			swap_b(t_pusw *lst);
void			swap_ab(t_pusw *lst);
void			push_a(t_pusw *lst);
void			push_b(t_pusw *lst);
void			rotate_a(t_pusw *lst);
void			rotate_b(t_pusw *lst);
void			rotate_ab(t_pusw *lst);
void			rev_rotate_a(t_pusw *lst);
void			rev_rotate_b(t_pusw *lst);
void			rev_rotate_ab(t_pusw *lst);

/*
**----------------------------------------------------------------------
**
**							utils
**----------------------------------------------------------------------
*/
void			ps_error(t_pusw *lst);
void			ps_free(t_pusw *lst);
int				ft_issort(t_pusw *lst);
int				ps_interact(t_pusw *lst, int ret);
void			ps_visu(t_pusw *lst);

#endif

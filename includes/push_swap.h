/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 11:57:58 by rgermain    ###    #+. /#+    ###.fr     */
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
	int		instruction;
	int		min;
	int		med;
	int		max;
	MINT	visu;
	MINT	time;
}				t_pusw;

int				check_arg(char **argv);
void			ps_error(t_pusw *lst);
t_pusw			*ps_struct_init(int argc, char **argv);
void			ps_debug(t_pusw *lst);
void			ps_debugs(t_pusw *lst, int nb, int index);
void			ps_free(t_pusw *lst);
void			ps_algo(t_pusw *lst);
int				ft_issort(t_pusw *lst);
void			ps_interact(t_pusw *lst, size_t instruction);
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

#endif

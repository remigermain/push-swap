/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/12 15:04:33 by rgermain    ###    #+. /#+    ###.fr     */
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
	int		time;
	char	visu;
	int		min;
	int		max;
}				t_puswc;

int				check_arg(char **argv);
void			ps_error(t_puswc *lst);
void			ps_free(t_puswc *lst);
int				ps_checker(t_puswc *lst);
int				ps_interact(t_puswc *lst, int ret);
void			ps_ivisu(t_puswc *lst);
void			ps_visu(t_puswc *lst);
void			ps_final_check(t_puswc *lst);
int				ft_issort(t_puswc *lst);
void			swap_a(t_puswc *lst);
void			swap_b(t_puswc *lst);
void			swap_ab(t_puswc *lst);
void			push_a(t_puswc *lst);
void			push_b(t_puswc *lst);
void			rotate_a(t_puswc *lst);
void			rotate_b(t_puswc *lst);
void			rotate_ab(t_puswc *lst);
void			rev_rotate_a(t_puswc *lst);
void			rev_rotate_b(t_puswc *lst);
void			rev_rotate_ab(t_puswc *lst);

#endif

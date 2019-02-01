/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   push_swap.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 09:33:45 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 11:44:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../libft/includes/libft.h"

typedef struct	s_pusw
{
	int		*stack_a;
	size_t		len_a;
	int		*stack_b;
	size_t		len_b;
	int		min;
	int		max;
}				t_pusw;

int		check_instruction(char **argv);
void	ps_error(t_pusw *lst);
t_pusw	*ps_struct_init(int argc, char **argv);
void	ps_debug(t_pusw *lst);
void	ps_free(t_pusw *lst);

#endif


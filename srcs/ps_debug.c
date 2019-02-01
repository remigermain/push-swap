/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_debug.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:19:05 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/01 11:38:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_debug(t_pusw *lst)
{
	size_t count;

	count = -1;
	ft_printf("\n//////   debug ////////\n\n");
	if (lst->stack_a != NULL)
	{
		ft_printf("    %{T_BLUE}[stack_a]%{T_EOC}  len = %d\n  ", lst->len_a);
		while (++count < lst->len_a)
			ft_printf("%d  ", lst->stack_a[count]);
	}
	ft_printf("\n\n");
	count = -1;
	if (lst->stack_b != NULL)
	{
		ft_printf("    %{T_YELLOW}[stack_b]%{T_EOC}  len = %d\n  ", lst->len_b);
		while (++count < lst->len_b)
			ft_printf("%d  ", lst->stack_b[count]);
	}
	ft_printf("\n\n min = %d\n max = %d\n\n", lst->min, lst->max);
}

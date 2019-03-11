/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 11:24:11 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pusw *lst)
{
	int	swap;

	if (lst->len_a > 0)
	{
		swap = lst->stack_a[lst->len_a];
		lst->stack_a[lst->len_a] = lst->stack_a[lst->len_a - 1];
		lst->stack_a[lst->len_a - 1] = swap;
		ps_putbuff(lst, "sa\n", 3);
	}
}

void	swap_b(t_pusw *lst)
{
	int	swap;

	if (lst->len_b > 0)
	{
		swap = lst->stack_b[lst->len_b];
		lst->stack_b[lst->len_b] = lst->stack_b[lst->len_b - 1];
		lst->stack_b[lst->len_b - 1] = swap;
		ps_putbuff(lst, "sb\n", 3);
	}
}

void	swap_ab(t_pusw *lst)
{
	int	swap;

	if (lst->len_a > 0 || lst->len_b > 0)
	{
		if (lst->len_a > 0)
		{
			swap = lst->stack_a[lst->len_a];
			lst->stack_a[lst->len_a] = lst->stack_a[lst->len_a - 1];
			lst->stack_a[lst->len_a - 1] = swap;
		}
		if (lst->len_b > 0)
		{
			swap = lst->stack_b[lst->len_b];
			lst->stack_b[lst->len_b] = lst->stack_b[lst->len_b - 1];
			lst->stack_b[lst->len_b - 1] = swap;
		}
		ps_putbuff(lst, "ss\n", 3);
	}
}

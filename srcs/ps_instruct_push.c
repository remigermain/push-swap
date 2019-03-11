/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/03/11 11:26:55 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pusw *lst)
{
	if (lst->len_b >= 0)
	{
		lst->stack_a[++lst->len_a] = lst->stack_b[lst->len_b--];
		ps_putbuff(lst, "pa\n", 3);
	}
}

void	push_b(t_pusw *lst)
{
	if (lst->len_a >= 0)
	{
		lst->stack_b[++lst->len_b] = lst->stack_a[lst->len_a--];
		ps_putbuff(lst, "pb\n", 3);
	}
}

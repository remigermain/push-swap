/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 11:59:26 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pusw *lst)
{
	if (lst->len_b >= 0)
	{
		lst->stack_a[++lst->len_a] = lst->stack_b[lst->len_b--];
		lst->instruction++;
		ft_printf("pa\n");
	}
}

void	push_b(t_pusw *lst)
{
	if (lst->len_a >= 0)
	{
		lst->stack_b[++lst->len_b] = lst->stack_a[lst->len_a--];
		lst->instruction++;
		ft_printf("pb\n");
	}
}

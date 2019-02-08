/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 12:19:52 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_stack_b(t_pusw *lst)
{
	int	len;

	len = lst->len_b;
	while (len > 0)
	{
		if (lst->stack_b[len] < lst->stack_b[len - 1])
			return (0);
		len--;
	}
	return (1);
}

int	sort_stack_a(t_pusw *lst)
{
	int	len;

	len = lst->len_a;
	while (len > 0)
	{
		if (lst->stack_a[len] > lst->stack_a[len - 1])
			return (0);
		len--;
	}
	return (1);
}

int	sort_realstack_a(t_pusw *lst)
{
	if ((find_min(lst->stack_a, lst->len_a) >
				find_max(lst->stack_b, lst->len_b)) && sort_stack_a(lst))
		return (1);
	return (0);
}

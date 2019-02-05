/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/05 17:22:37 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pusw *lst)
{
	int len;

	len = lst->len_a;
	if (lst->len_a > 0)
	{
		while (len >= 0)
		{
			lst->stack_a[len + 1] = lst->stack_a[len];
			len--;
		}
		lst->stack_a[0] = lst->stack_a[lst->len_a + 1];
	}
	lst->instruction++;
	ft_printf("ra\n");
}

void	rotate_b(t_pusw *lst)
{
	int len;

	len = lst->len_b;
	if (lst->len_b > 0)
	{
		while (len >= 0)
		{
			lst->stack_b[len + 1] = lst->stack_b[len];
			len--;
		}
		lst->stack_b[0] = lst->stack_b[lst->len_b + 1];
	}
	lst->instruction++;
	ft_printf("rb\n");
}

void	rotate_ab(t_pusw *lst)
{
	rotate_a(lst);
	rotate_b(lst);
}

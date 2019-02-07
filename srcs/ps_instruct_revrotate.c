/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 13:15:41 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_pusw *lst)
{
	int len;

	len = 0;
	if (lst->len_a > 0)
	{
		lst->stack_a[lst->len_a + 1] = lst->stack_a[0];
		while (len < (lst->len_a + 1))
		{
			lst->stack_a[len] = lst->stack_a[len + 1];
			len++;
		}
	}
	lst->instruction++;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_pusw *lst)
{
	int len;

	len = 0;
	if (lst->len_b > 0)
	{
		lst->stack_b[lst->len_b + 1] = lst->stack_b[0];
		while (len < (lst->len_b + 1))
		{
			lst->stack_b[len] = lst->stack_b[len + 1];
			len++;
		}
	}
	lst->instruction++;
	ft_printf("rrb\n");
}

void	rev_rotate_ab(t_pusw *lst)
{
	int len;

	len = 0;
	if (lst->len_b > 0)
	{
		lst->stack_b[lst->len_b + 1] = lst->stack_b[0];
		while (len < (lst->len_b + 1))
		{
			lst->stack_b[len] = lst->stack_b[len + 1];
			len++;
		}
	}
	len = 0;
	if (lst->len_a > 0)
	{
		lst->stack_a[lst->len_a + 1] = lst->stack_a[0];
		while (len < (lst->len_a + 1))
		{
			lst->stack_a[len] = lst->stack_a[len + 1];
			len++;
		}
	}
	lst->instruction++;
	ft_printf("rrr\n");
}

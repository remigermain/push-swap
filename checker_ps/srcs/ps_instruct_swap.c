/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/07 13:46:28 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	swap_a(t_puswc *lst)
{
	int	swap;

	if (lst->len_a > 0)
	{
		swap = lst->stack_a[lst->len_a];
		lst->stack_a[lst->len_a] = lst->stack_a[lst->len_a - 1];
		lst->stack_a[lst->len_a - 1] = swap;
	}
	lst->instruction++;
}

void	swap_b(t_puswc *lst)
{
	int	swap;

	if (lst->len_b > 0)
	{
		swap = lst->stack_b[lst->len_b];
		lst->stack_b[lst->len_b] = lst->stack_b[lst->len_b - 1];
		lst->stack_b[lst->len_b - 1] = swap;
	}
	lst->instruction++;
}

void	swap_ab(t_puswc *lst)
{
	int	swap;

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
	lst->instruction++;
}

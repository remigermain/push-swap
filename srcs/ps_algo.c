/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/13 18:17:14 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/13 18:50:53 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_final(t_pusw *lst)
{
	if (lst->len_a > 0 && lst->len_b > 0 &&
				lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1] &&
			lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
		swap_ab(lst);
	else if (lst->len_a > 0 &&
		lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
		swap_a(lst);
}

static void	swap_split(t_pusw *lst)
{
	if (lst->len_a > 0 && lst->len_b > 0 &&
				lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1] &&
			lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
		swap_ab(lst);
	else if (lst->len_a > 0 &&
		lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
		swap_a(lst);
	else if (lst->len_b > 0 &&
		lst->stack_b[lst->len_b] > lst->stack_b[lst->len_b - 1])
		swap_b(lst);

}

static void	split_stack(t_pusw *lst, char sens)
{
	ps_visu(lst);
	find_mid_med(lst);
	sens = find_midsens(lst);
	while (!sort_realstack_a(lst) && lst->len_a != -1)
	{
		if (lst->stack_a[lst->len_a] <= lst->pivot)
		{
			push_b(lst);
			find_mid_med(lst);
			sens = find_midsens(lst);
		}
		else if (lst->len_b > 0 &&
				lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			rotate_ab(lst);
		else
			rotate_a(lst);
		ps_visu(lst);
	}
}

static void	push_final(t_pusw *lst, char sens)
{
	lst->max = find_max(lst->stack_b, lst->len_b);
	lst->max_n = find_next_max(lst->stack_b, lst->len_b, lst->max);
	sens = find_sens2(lst);
	while (lst->len_b != -1)
	{
		ps_visu(lst);
		if (lst->len_b == 0 || lst->stack_b[lst->len_b] == lst->max ||
			(lst->stack_b[lst->len_b] == lst->max_n))
		{
			push_a(lst);
			if (lst->stack_a[lst->len_a] == lst->max_n)
				sens = find_sens(lst, lst->max);
			else
			{
				swap_final(lst);
				lst->max = find_max(lst->stack_b, lst->len_b);
				lst->max_n = find_next_max(lst->stack_b, lst->len_b, lst->max);
				sens = find_sens2(lst);
			}
		}
		else if (sens == 1)
			rotate_b(lst);
		else
			rev_rotate_b(lst);
	}
}

void		ps_algo(t_pusw *lst)
{
	if (!ft_issort(lst))
	{
		if (lst->len_a == 1)
			swap_a(lst);
		else
		{
			split_stack(lst, 0);
			push_final(lst, 0);
		}
		ps_visu(lst);
	}
	ps_visu(lst);
}

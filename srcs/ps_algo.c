/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/11 19:21:34 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/11 19:21:47 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_prevstack(t_pusw *lst, char sens)
{
	find_mid_med(lst);
	while ((lst->len_b + 1) < lst->len_a)
	{
		ps_visu(lst);
		if (lst->stack_a[lst->len_a] <= lst->med)
		{
			push_b(lst);
			if (lst->stack_b[lst->len_b] == lst->med)
				find_mid_med(lst);
		}
		else if (lst->stack_b > 0 &&
				lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			rotate_ab(lst);
		else
			rotate_a(lst);
	}
}

static void	split_stack(t_pusw *lst, char sens)
{
	int	val;
	int	min;

	val = 8;
	ps_visu(lst);
	find_mid_med(lst);
	while (!sort_realstack_a(lst) && lst->len_a != -1)
	{
		if (((lst->len_a + lst->len_b + 2) < val) && lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1] &&
				lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			swap_ab(lst);
		else if (((lst->len_a + lst->len_b + 2) < val) && lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
			swap_a(lst);
		else if (((lst->len_a + lst->len_b + 2) < val) && lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			swap_b(lst);
		else if (lst->stack_a[lst->len_a] <= lst->med)
		{
			push_b(lst);
			if (lst->stack_b[lst->len_b] == lst->med)
				find_mid_med(lst);
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
		if (lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1] &&
				lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
			swap_ab(lst);
		else if (lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
			swap_a(lst);
		else if (lst->len_b == 0 || lst->stack_b[lst->len_b] == lst->max ||
			(lst->stack_b[lst->len_b] == lst->max_n))
		{
			push_a(lst);
			if (lst->stack_a[lst->len_a] == lst->max_n)
				sens = find_sens(lst, lst->max);
			else
			{
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
		split_prevstack(lst, 0);
		if (!sort_realstack_a(lst))
			split_stack(lst, 0);
		push_final(lst, 0);
	}
	ps_visu(lst);
}

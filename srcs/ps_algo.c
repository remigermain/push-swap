/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/08 13:05:42 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_stack(t_pusw *lst, char sens)
{
	lst->med = find_med(lst->stack_a, lst->len_a);
	sens = find_midsens(lst);
	while ((lst->len_b + 1) < lst->len_a)
	{
		ps_visu(lst);
		if (lst->stack_a[lst->len_a] <= lst->med)
		{
			push_b(lst);
			sens = find_midsens(lst);
		}
		else if (sens == 1 && lst->stack_b > 0 &&
				lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			rotate_ab(lst);
		else if (sens == 0 && lst->stack_b > 0 &&
				lst->stack_b[lst->len_b] > lst->stack_b[0])
			rev_rotate_ab(lst);
		else if (sens == 1)
			rotate_a(lst);
		else
			rev_rotate_a(lst);
	}
}

static void	split_reste(t_pusw *lst, char sens)
{
	lst->med = find_med(lst->stack_a, lst->len_a);
	sens = find_midsens(lst);
	while (!sort_realstack_a(lst))
	{
		ps_visu(lst);
		if (((lst->len_a + lst->len_b + 2) < 8) && lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1] &&
				lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			swap_ab(lst);
		else if (((lst->len_a + lst->len_b + 2) < 8) && lst->len_a > 0 && lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
			swap_a(lst);
		else if (((lst->len_a + lst->len_b + 2) < 8) && lst->len_b > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			swap_b(lst);
		else if (lst->stack_a[lst->len_a] <= lst->med)
		{
			push_b(lst);
			if (lst->med == lst->stack_b[lst->len_b])
				lst->med = find_med(lst->stack_a, lst->len_a);
			sens = find_midsens(lst);
		}
		else if (sens == 1 && lst->stack_b > 0 &&
				lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
			rotate_ab(lst);
		else if (sens == 0 && lst->stack_b > 0 &&
				lst->stack_b[lst->len_b] > lst->stack_b[0])
			rev_rotate_ab(lst);
		else if (sens == 1)
			rotate_a(lst);
		else
			rev_rotate_a(lst);
	}
	ps_visu(lst);
}

static void	put_rest(t_pusw *lst, char sens, char ind_m, char ind_nm)
{
	lst->max = find_max(lst->stack_b, lst->len_b);
	lst->max_n = find_next_max(lst->stack_b, lst->len_b, lst->max);
	sens = find_sens(lst, lst->max);
	while (lst->len_b != -1)
	{
		ps_visu(lst);
		if ((lst->stack_b[lst->len_b] == lst->max || lst->len_b == 0 ||
			(lst->stack_b[lst->len_b] == lst->max_n && ind_m == 0)))
		{
			if (lst->stack_b[lst->len_b] == lst->max_n && ind_m == 0)
				ind_m = 1;
			push_a(lst);
			if (lst->stack_a[lst->len_a] == lst->max && ind_m == 1)
			{
				if (lst->len_a > 0 && lst->stack_b[lst->len_b] < lst->stack_b[lst->len_b - 1])
					swap_ab(lst);
				else
					swap_a(lst);
				ind_m = 0;
			}
			if (ind_m == 0)
			{
				lst->max = find_max(lst->stack_b, lst->len_b);
				lst->max_n = find_next_max(lst->stack_b, lst->len_b, lst->max);
			}
			sens = find_sens(lst, lst->max);
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
		split_stack(lst, 0);
		split_reste(lst, 0);
		put_rest(lst, 0, 0, 0);
	}
	ps_visu(lst);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ps_algo.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rgermain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/01 11:55:41 by rgermain     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/06 09:34:29 by rgermain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_stack(int *stack, int len)
{
	while (len > 0)
	{
		if (stack[len] > stack[len - 1])
			return (-1);
		len--;
	}
	return (1);
}

static void	split_stack(t_pusw *lst)
{
	while (lst->len_b < lst->len_a)
	{
		if (lst->stack_a[lst->len_a] <= lst->med)
			push_b(lst);
		else
			rotate_a(lst);
	}
}

static int	ps_algo2(t_pusw *lst, int pivot)
{
	if (lst->len_a <= pivot)
	{
		pivot++;
		while (lst->len_b != -1)
			push_a(lst);
	}
	return (pivot);
}

void		ps_algo(t_pusw *lst)
{
	int pivot;

	pivot = 0;
	if (!ft_issort(lst))
	{
		if (lst->len_a > 4)
			split_stack(lst);
		while (!ft_issort(lst))
		{
			ps_debugs(lst, 9, 0);
			usleep(100000);
			if (sort_stack(lst->stack_a, lst->len_a) == 1)
				pivot = lst->len_a;
			if (lst->stack_a[lst->len_a] > lst->stack_a[0])
				rotate_a(lst);
			if (lst->len_b != -1 &&
					lst->stack_b[lst->len_b] > lst->stack_a[lst->len_a])
				push_a(lst);
			if (lst->stack_a[lst->len_a] > lst->stack_a[lst->len_a - 1])
				swap_a(lst);
			else if (sort_stack(lst->stack_a, lst->len_a) == -1)
				push_b(lst);
			else if (lst->stack_b[lst->len_b] < lst->stack_b[0])
				rev_rotate_b(lst);
			pivot = ps_algo2(lst, pivot);
		}
	}
	ps_debugs(lst, 9, 0);
	usleep(100000);	
}
